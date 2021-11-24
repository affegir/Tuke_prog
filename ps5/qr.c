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

void encode_string(const char string[], bool bytes[strlen(string)+1][8])
{
    bool o[8];
    for (int i = 0; i<strlen(string)+1; i++)
    {
        char b = string[i];
        encode_char(b,o);
        for(int j = 0; j < 8; j++)
        {
            bytes[i][j] = o[j];
        }
        
    }
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows])
{
    char o[8];
    char c = 0;
    for (int i = 0; i<rows; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            o[j] = bytes[i][j];
            
            for (int l = 0; l < 8; ++l)
            {
                c = c * 2;
                c = c + (o[l]);
                string[i] = c;
            }
        }
        
    }
}


int main()
{
	return 0;
}
