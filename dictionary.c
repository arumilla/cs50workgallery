// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

//total number of words
int s = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word);
    if (table[index] == NULL){
        return false;
    }
   
        for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next){
            if (strcasecmp(cursor->word, word) == 0){
                return true;
            }
        }
    
    return false;
}

// Hashes word to a number (djb2)
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++)){
        hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */
    }
    return hash%N;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
       return false; 
    }
    
    //list of words
    char w[LENGTH+1];
    //index of words for hash
    int index;
    
    //read words into w, stop when end of file
    while (fscanf(file, "%s", w) != EOF){
        
        s++;
        
        //create a node called words
        node *words = malloc(sizeof(node));
        //if not enough space then return null
        if (words == NULL){
            return false;
        }
        //copy the string from file into the word thing in the node
        strcpy(words->word,w);
        //set pointer to null
        words->next = NULL;
        
        //find the index for the word
        index = hash(w);
        
        //if word is at begining of linked lists
        if (table[index] == NULL){
            table[index] = words;
        }
        //if there is already a linked list
        else {
            words->next = table[index];
            table[index] = words;
        }
    }
    
    fclose(file);
    
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return s;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++){
        node *tmp = table[i];
        node *cursor = tmp;
        
        while (cursor != NULL){
            tmp = cursor;
            cursor = cursor -> next;
            free(tmp);
        }
    }
    return true;
}
