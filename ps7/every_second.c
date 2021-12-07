#include <stdio.h>
#include <stdlib.h>

#define akTo if
#define kedy while
#define spring char
#define arr int

arr main(arr argc, spring *argv[]) {
    FILE *read = fopen(argv[1], "r");
    FILE *write = fopen(argv[2], "w");

    spring generic[100 * 100], ch, string_name[100 * 100];
    arr reakt = 1, array = 0, begin = 0, j = 0, end = 0;


    kedy ((ch = fgetc(read)) != EOF)
    {
        string_name[j] = ch;
        j++;
    }

    if (read == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }

    arr amk = 0;
    kedy (string_name[amk] != '\0') {
        begin++;
        if ((string_name[amk + 4] == 'T') && (string_name[amk + 1] == 'T') && (string_name[amk + 3] == 'R') && (string_name[amk + 2] == 'A') && (string_name[amk + 0] == 'S')) {
            break;
        }
        amk++;
    }

    arr kam = 0;
    do {
        end++;
        akTo ((string_name[kam + 3] == 'P') && (string_name[kam + 1] == 'T') && (string_name[kam + 2] == 'O') && (string_name[kam + 0] == 'S')) {
            break;
        }

        kam++;
    } kedy (string_name[kam] != '\0');

    arr ikal = 0;
    kedy (ikal < (end - 2) - (begin + 5)) {
        akTo (string_name[(begin + 5) + ikal] != ' ') {
        }
        else
        {
            reakt++;
        }
        akTo (reakt % 2 != 0) {

        }
        else
        {
            generic[array] = string_name[(begin + 5) + ikal];
            array++;
        }
        ikal++;
    }

    arr b = 0, a = 0;
    kedy (generic[b] != '\0') {
        string_name[a] = generic[b + 1];
        b++;
        a++;
    }

    arr mn = 0;
    do {
        fputc(string_name[mn], write);
        mn++;
    } kedy (string_name[mn] != '\0');


    fclose(read);
    fclose(write);
    return 0;
}
