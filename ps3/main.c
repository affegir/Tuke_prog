#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"
 
int main (void)
{


    srand( (unsigned int)time(NULL)/2 );
    char secret[30];
    int error = get_word(secret);
    if (error == 1) return error;
   
 
   
    hangman(secret);
 
    return error;
}
