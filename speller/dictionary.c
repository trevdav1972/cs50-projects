// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;
int words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
// TODO
    int hashs = hash(word);
    node *checker = table[hashs];
    while (checker != NULL)
    {
        if (strcasecmp(word, checker->word) == 0)
        {
            return true;
        }
        checker = checker->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
        int sum;
        int a;
        int b;
        int c;

        a = tolower(word[0]);
        c = a * 26;
        b = c + tolower(word[1]);
        sum = b;

        return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *n = fopen(dictionary, "r");
    if (n == NULL)
    {
        printf("Error opening file!\n");
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(n, "%s", word) != EOF)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            printf("Not enough Space!\n");
            return false;
        }
        strcpy(new->word, word);
        new->next = NULL;
        
        strcpy(new->word, word);
        int hashs = hash(word);
        new->next = table[hashs];
        table[hashs] = new;
        words++;
    }
    fclose(n);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
// TODO
    node *cursor;
    node *tmp;

    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
