#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string n =  get_string("What's your name?\n");
    printf("hello, %s\n", n);
}