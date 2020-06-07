#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, string argv[])
{

    int key = atoi(argv[1]);
    char chara;

    //char arg[strlen(argv[1])] = stcpy( arg, argv[1]);
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return -1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key \n");
                return -1;
            }
        }
        
        string change = get_string("plaintext: ");
        printf("ciphertext: ");
    
        for (int i = 0; change[i] != '\0'; i++){
            chara = change[i];
            int ini = 0;
            int inf = 0;
        
            if (isalpha(chara))
            {
                if (isupper(chara))
                {
                    /*ini = chara - 65;
                    inf = (ini + key) % 26;*/
                
                    chara = chara + key;
                    
                    printf("%c", chara);
                }
                else
                {
                    /*ini = chara - 97;
                    inf = (ini + key) % 26;*/
                
                chara = chara + key;
                
                printf("%c", chara);
                }
            }
            else 
            {
                printf("%c", chara);
            }
            
            
        }
        printf("\n");
    }
    
}