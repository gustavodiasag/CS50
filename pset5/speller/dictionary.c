// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int words_loaded = 0;

// Number of buckets in hash table
const unsigned int N = LENGTH * 122;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_index = hash(word);
    node *cursor = table[hash_index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        strcpy(new_node->word, word);
        new_node->next = NULL;


        int hash_index = hash(word);

        if (table[hash_index] == NULL)
        {
            table[hash_index] = new_node;
        }
        else
        {
            new_node->next = table[hash_index];
            table[hash_index] = new_node;
        }
        words_loaded++;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words_loaded;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp = cursor;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
