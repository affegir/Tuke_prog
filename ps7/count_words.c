#include <stdio.h>



int checkSymbol(char c) {
    char ananas[6];
    const char* search = "ANANAS";

    for (int i = 0; i < 5; ++i) ananas[i] = ananas[i + 1];

    if (c >= 'a') c -= (int)('a' - 'A');

    ananas[5] = c;

    for (int i = 0; i < 5; ++i)
        if (ananas[i] != search[i]) return 0;

    return 1;
    }

int main() {
    FILE* f = fopen("bananas.txt", "rt");
    int c, count = 0;

    while ((c = fgetc(f)) != EOF) count += checkSymbol(c);

    fclose(f);
    f = fopen("bananas.txt", "wt");
    fprintf(f, "%d\n", count);
    fclose(f);
    }
