#include <stdio.h>
#include <stdbool.h>
 


void encode_char(const char character, bool bits[8])
{
    char p = character;
    int i, o = 1;
    for (i = 7; i >= 0; i--)
    {
        bits[i] = p & o;
        p >>= 1;
    }
}

char decode_byte(const bool bits[8])
{

char c = 0;
    for (int i = 0; i < 8; ++i)
    {
        c *= 2;
        c += (bits[i]);
    } 
    return c;
        }


int main()
{
	return 0;
}
