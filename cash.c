#include <stdio.h>
#include <cs50.h>
/*converts an amount of money into the least amount of it in coins*/
int main(void)
{
    int coins = 0;
    int cents;
    
    float owed;
    do
    {
        owed = get_float("Owed: \n");
    }
    while(!(owed >= 0));
    
    cents = (int)(owed * 100);
    
    coins += (cents/25);
    cents = (cents%25);
    
    coins += (cents/10);
    cents = (cents%10);
    
    coins += (cents/5);
    cents = (cents%5);
    
    coins += (cents/1);
    
    printf("Coins: %i\n", coins);
}
