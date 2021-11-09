#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "hangman.h"


int get_word(char secret[]) {
    // check if file exists first and is readable
    FILE* fp = fopen(WORDLIST_FILENAME, "rb");
    if (fp == NULL) {
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do {
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if (result != EOF)
            break;
    } while (1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]) {
    int i;
    char* poisk;
    poisk = (char*)malloc(30);

    for (i = 0; i < strlen(secret); i++) {
        poisk = strchr(letters_guessed, secret[i]);
        while (poisk == NULL) {
            return 0;
        }
    }
    return 1;
}
void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]) {
    int i;
    for (i = 0; secret[i]; i++){
        if (strchr(letters_guessed, secret[i]) != NULL){
            guessed_word[i] = secret[i];
        }
        else{
            guessed_word[i] = '_';
        }
    }
    guessed_word[i] = '\0';
}









void get_available_letters(const char letters_guessed[], char available_letters[])
 {
     int i, j = 0;
     char *poisk, bkvi[] = "abcdefghijklmnopqrstuvwxyz";

     poisk = (char *) malloc(15);
     for (i = 0; i < strlen(bkvi); i++){
         poisk = strchr(letters_guessed, bkvi[i]);
         if (poisk == NULL){
             available_letters[j++] = bkvi[i];
             }
         else {
                continue;
           }
     available_letters[j] = '\0';
          }
}

void hangman(const char secret[]){
	printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %d letters long.\n", (int)strlen(secret));
    printf("-------------\n");

    char available_letters[27] = "abcdefghijklmnopqrstuvwxyz", letters_guessed[27] = { 0 }, guessed_word[30] = { 0 }, input_word[30] = { 0 };     
    int hodov = 8, igra = 1, pobeda = 0, ku = 0;
    /*
    u - использованные буквы
    w - как выглядит на экране слово
    p - введенные пользователем буквы 
    ku - количество букв в u

    */

    while (igra > 0){
        printf("You have %d guesses left.\n", hodov);
        printf("Available letters: %s\n", available_letters);
        printf("Please guess a letter: ");
        fgets(input_word, 30, stdin);
        for (int i = 0; input_word[i]; i++){
            if (input_word[i] == '\n') input_word[i] = '\0';
            if (isalpha(input_word[i])) input_word[i] = tolower(input_word[i]);
        }
        
        int result = 0;
        int error = 0;
        for (int i = 0; input_word[i]; i++){
            if (!isalpha(input_word[i])) continue;   

            if (strchr(letters_guessed, input_word[i]) != NULL)
                error++;    
            else
                if (strchr(secret, input_word[i]) != NULL)
                    result++; 
        }

        if (result < 1){
            printf("Oops! That letter is not in my word:");
            hodov--;
        }
        else if (error > 0) printf("Oops! You've already guessed that letter:");
        else    printf("Good guess:");

        for (int i = 0; input_word[i]; i++){
            if (isalpha(input_word[i]) && strchr(letters_guessed, input_word[i]) == NULL)
                letters_guessed[ku++] = input_word[i];
        }

        get_guessed_word(secret, letters_guessed, guessed_word);
        get_available_letters(letters_guessed, available_letters);

        for (int i = 0; guessed_word[i]; i++) 
            printf("%2c", guessed_word[i]);
        printf("\n-------------\n");
        if (hodov == 0) igra = 0;
        if (is_word_guessed(secret, letters_guessed)){
            pobeda = 1;
            igra = 0;
        }
    }
    if (pobeda > 0)    printf("Congratulations, you won!\n");
    else        printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
}

