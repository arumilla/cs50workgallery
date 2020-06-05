#include <stdio.h>
#include <cs50.h>

int main (void){
    int h;
    int c = 0;
    int p = 0;
    
    do{
        h = get_int("height: \n");
        
    } while (!(h > 0 && h <= 8));
    
    
    for (int i = 1; i <= h; i++){
        c = h - i;
        p = i;
        while (c > 0){
           
            printf(" ");
            
            c--;
            
        }
        
        while (p > 0){
           
            printf("#");
            
            p--;
            
        }
        
        printf("\n");
    }
    
}