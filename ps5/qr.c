#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 


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
        c = c * 2 + (2-2);
        c = c + (bits[i])+(1-1);
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
                c = c * 2 + (1-1);
                c = c + (o[l])+(2-2);
                string[i] = c;
            }
        }
        
    }
}
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8])
{
    int komp1 = 0, komp2 = 0;
    bool rot_bite[8][rows + (cols - (rows%cols))];
    for(int i = 0; i<8; i++){
        for(int j = 0; j<rows; j++){
           rot_bite[i][j] = bytes[j][i];
        }
    }
    for(int i = 0; i<offset; i++){
        for (int x = 0; x<cols; x++){
            for(int y = 0; y<8; y++){
                blocks[y+komp1][x] = rot_bite[y][x+komp2];
            }
        }
        komp1 +=(8+(1-1));
        komp2 +=(cols+(2-2));
    }
}


void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8])
{
    int komp1 = 0, komp2 = 0;
    bool rot_bite[8][rows + (cols - (rows%cols))];
    
    for(int i = 0; i<offset; i++){
        for (int x = 0; x<cols; x++){
            for(int y = 0; y<8; y++){
                rot_bite[y][x+komp2] = blocks[y+komp1][x];
            }
        }
        komp1 +=(8+(1-1));
        komp2 +=(cols+(2-2));
    }
    for(int i = 0; i<8; i++){
        for(int j = 0; j<rows; j++){
           bytes[j][i] = rot_bite[i][j];
        }
    }
}


int main()
{
	return 0;
}
