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

    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key \n");
                return 1;
            }
        }
        
        string change = get_string("plaintext: ");
        printf("ciphertext: ");
    
        for (int i = 0; change[i] != '\0'; i++){
            chara = change[i];
            int check = 0;
            int a = 0;
        
            if (isalpha(chara))
            {
                if (isupper(chara))
                {
                    check = chara + key;
                    if (check > 90){
                        a = chara - 65;
                        chara = ((a + key)%26) + 65;
                    }
                    else {
                        chara = chara + key;
                    }
                    
                    printf("%c", chara);
                }
                else
                {
                    check = chara + key;
                    if (check > 122)
                    {
                        a = chara - 97;
                        chara = ((a + key)%26) + 97;
                    }
                    else {
                        chara = chara + key;
                    }
                    
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