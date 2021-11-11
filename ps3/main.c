#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"

int main( int argc, char *argv[]) {
  srand(time(NULL));
  char secret[15];
  get_word(secret);
  hangman(secret);
  
  return 0;
}
