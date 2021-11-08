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
    int i, o, p = 'z' - 'a' + 2;
    for (i = 0; i < p; i++)
    {
        if (strchr(letters_guessed, available_letters[i]) != NULL)
        {
            for (o = i + 1; o < p; o++)
                available_letters[o - 1] = available_letters[o];
        }
    }
}

void hangman(const char secret[])
{
    printf("Wellcome to the game, Hangman!\n");
    printf("I'm thinking of a word that is %d letters long.\n", (int)strlen(secret));
    printf("-------------\n");

    char d[27] = "abcdefghijklmnopqrstuvwxyz", u[27] = { 0 }, w[30] = { 0 }, p[30] = { 0 };     
    int hodov = 8, igra = 1, pobeda = 0, ku = 0;                   

    while (igra > 0){
        printf("You have %d guesses left.\n", hodov);
        printf("Available letters: %s\n", d);
        printf("Please guess a letter: ");
        fgets(p, 30, stdin);
        for (int i = 0; p[i]; i++){
            if (p[i] == '\n') p[i] = '\0';
            if (isalpha(p[i])) p[i] = tolower(p[i]);
        }
        
        int result = 0;
        int error = 0;
        for (int i = 0; p[i]; i++){
            if (!isalpha(p[i])) continue;   

            if (strchr(u, p[i]) != NULL)
                error++;    
            else
                if (strchr(secret, p[i]) != NULL)
                    result++; 
        }

        if (result < 1){
            printf("Oops! That letter is not in my word: ");
            hodov--;
        }
        else if (error > 0) printf("Oops! You've already guessed that letter: ");
        else    printf("Good guess: ");

        for (int i = 0; p[i]; i++){
            if (isalpha(p[i]) && strchr(u, p[i]) == NULL)
                u[ku++] = p[i];
        }

        get_guessed_word(secret, u, w);
        get_available_letters(u, d);

        for (int i = 0; w[i]; i++) 
            printf("%2c", w[i]);
        printf("\n-------------\n");
        if (hodov == 0) igra = 0;
        if (is_word_guessed(secret, u)){
            pobeda = 1;
            igra = 0;
        }
    }
    if (pobeda > 0)    printf("Congratulations, you won!\n");
    else        printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
}
