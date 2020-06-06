#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_words(string str){
    
    int c = 1;
    
    for(int i = 0; i < strlen(str); i++){
        
        if (isblank(str[i]) != 0){
            c++;
        }
    }
    
    return c;
}

int count_letters(string str){
    int c = 0;
    
    for(int i = 0; i < strlen(str); i++){
        
        if (isalpha(str[i]) != 0){
            c++;
        }
    }
    
    return c;
}

int count_sentences(string str){
    int c = 0;
    
    for(int i = 0; i < strlen(str); i++){
        
        if (str[i] == '.' || str[i] == '!' || str[i]== '?'){
            c++;
        }
    }
    
    return c;
}

int main(void){
    string t = get_string("Text: ");
    
    float le = (float)count_letters(t);
    float wo = (float)count_words(t);
    float se = (float)count_sentences(t);
    
    float d = 100/wo;
    
    float L = le*d;
    float S = se*d;
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index < 1){
        printf("Before Grade 1\n");
    }
    else if (index > 16){
        printf(" Grade 16+\n");
    }
    else{
        printf("Grade %i\n", index);
    }

}

