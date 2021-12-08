#include <stdio.h>


#define funk int
#define vrat return
#define how if
#define pause break

funk main(funk argc, char* argv[])
{
    FILE *banan = fopen(argv[1], "r");
    float math, algebra = 0;
    int computer_calk = 0, calkut = 0, i = 0, name = 0, q = 0, w;
    char frukt[] = "ananas", letter[5000], nation, ckeck_firest, check_second, first, second;

    how (argc < 2)
    {
        printf("wrong number\n");
        vrat 0;
    }

    how (banan == NULL)
    {
        printf("Cant open file\n");
        vrat 0;
    }

    for (; (nation = fgetc(banan)) != EOF; i++)
    {
        letter[i] = nation;
    }

    int qwe = 0;
    do
    {
        how (letter[qwe] == EOF)
            pause;

        how (letter[qwe] == ' ' && letter[qwe] >= ' ' && letter[qwe] <= ' ')
        {
        }
        else
        {
            int mk = 0;
            do
            {
                ckeck_firest = (letter[qwe] >= 'A' && letter[qwe] <= 'Z') ? (letter[qwe] + 32) : (letter[qwe]);
                check_second = (letter[qwe + 1] >= 'A' && letter[qwe + 1] <= 'Z') ? (letter[qwe + 1] + 32) : (letter[qwe + 1]);
                how ((ckeck_firest == 'a' && check_second == 'n') || name == 1)
                {
                    how (ckeck_firest != frukt[mk])
                    {
                        name = 0;
                        pause;
                    }
                    else
                    {
                        name = 1;
                        calkut++;
                        qwe++;
                    }
                }
                mk++;

            } while (mk < 6);
        }

        how (calkut == 6)
            computer_calk++;

        calkut = 0;
        qwe++;
    } while (qwe < 5000);

    banan = fopen(argv[1], "w");

    how (computer_calk != 10 && computer_calk <= 10)
    {
        char symb;
        symb = computer_calk + '0';
        fputc(symb, banan);
    }
    else
    {
        q = computer_calk / 10;
        math = computer_calk / 10.0;
        algebra = (math + 0.0 - q) * 10;
        w = algebra;
        first = q + '0';
        second = w + '0';
        fputc(first, banan);
        fputc(second, banan);
    }

    fclose(banan);
    vrat 0;
}
