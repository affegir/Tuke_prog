#include <stdio.h>
 #include <ctype.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
 #include <stdbool.h>
 #include "hangman.h"

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]) { 
    int secret_index = 0; 
 
    char secret_letter = '\0'; 
 
    while (secret[secret_index] != '\0') { 
        secret_letter = secret[secret_index]; 
 
        char guessed_letter = '\0'; 
        int guessed_index = 0; 
        bool is_secret_letter_in_gueesed_letters = false; 
 
        while (is_secret_letter_in_gueesed_letters == false && letters_guessed[guessed_index] != '\0') { 
            guessed_letter = letters_guessed[guessed_index]; 
            if (secret_letter == guessed_letter) 
                is_secret_letter_in_gueesed_letters = true; 
            guessed_index++; 
        } 
        if (is_secret_letter_in_gueesed_letters == false) 
            guessed_word[secret_index] = '_'; 
        else 
            guessed_word[secret_index] = guessed_letter; 
 
        secret_index++; 
    } 
    guessed_word[secret_index] = '\0'; 
 
    for (int i = 0; i < strlen(secret) - 1; i++) 
        printf("%c ", guessed_word[i]); 
 
    printf("%c\n", guessed_word[strlen(secret) - 1]); 
} 
 
 
void hangman(const char secret[]) { 
    int getWord, order; 
    int y, x; 
    int letter, secret_leter; 
    int massive = strlen(secret); 
    order = 0; 
    getWord = 8; 
    char guessed_letters[100]; 
 
    printf("Welcome to the game, Hangman!\n"); 
    printf("I am thinking of a word that is %d letters long.\n", massive); //// 
 
    char available_letters[100]; 
    guessed_letters[0] = '\0'; 
 
    while (getWord > 0) { 
        printf("-------------\n"); /// 
        printf("You have %d guesses left.\n", getWord); 
        printf("Available letters: "); /// 
        get_available_letters(guessed_letters, available_letters); 
        printf("Please guess a letter: "); 
        char guessed_word[100]; 
        scanf("%s", guessed_word); 
 
        if (strlen(guessed_word) > 1) { 
            if (is_word_guessed(secret, guessed_word) == 1) { 
                printf("Congratulations, you won!\n"); 
                getWord = 0; 
            } else { 
                printf("Sorry, bad guess. The word was %s.\n", secret); 
                getWord = -1; 
            } 
        } else { 
            char guessed_letter = guessed_word[0]; 
            guessed_letter = tolower(guessed_letter); 
 
            if (guessed_letter > 122 || guessed_letter < 97) { 
                ++getWord; 
                printf("Oops! %s is not a valid letter: ", guessed_word); 
                get_guessed_word(secret, guessed_letters, guessed_word); 
            } else { 
                int alphabet = strlen(available_letters); 
                letter = 0; 
                for (y = 0; y < alphabet; y++) { 
                    if (available_letters[y] == guessed_letter) 
                        letter = 0 + 1; 
                } 
                if (letter == 0) { 
                    ++getWord; 
                    printf("Oops! You've already guessed that letter: "); 
                    get_guessed_word(secret, guessed_letters, guessed_word); 
                } else { 
                    guessed_letters[order] = guessed_letter; 
                    ++order; 
                    guessed_letters[order + 0 + 1] = '\0'; 
                    secret_leter = 0; 
 
                    for (x = 0; x < massive; x++) { 
                        if (secret[x] == guessed_letter) 
                            secret_leter = 1; 
                    } 
                    if (secret_leter == 1) { 
                        printf("Good guess: "); 
                        ++getWord; 
                    } else 
                        printf("Oops! That letter is not in my word: "); 
                    get_guessed_word(secret, guessed_letters, guessed_word); 
 
                    if (is_word_guessed(secret, guessed_word) == 1) { 
                        printf("-------------\n"); 
                        getWord = 0; 
                        printf("Congratulations, you won!\n"); 
                    } 
                } 
            } 
        }
        --getWord; 
 
        if (getWord == 0) { 
            printf("-------------\n"); 
            printf("Sorry, you ran out of guesses. The word was %s.\n", secret); 
        } 
    } 
}

