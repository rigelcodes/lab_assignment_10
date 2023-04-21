#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Trie {
    int flag;
    struct Trie *children[26];
};

void insert(struct Trie **ppTrie, char *word) 
{
    // check for NULL
    if(*ppTrie == NULL)
    {
        return;
    }
    struct Trie *temp = *ppTrie;
    int length = strlen(word);

    // insertion
    for (int x = 0; x < length; x++) 
    {
        int index = word[x] - 'a';
        if (temp->children[index] == NULL) 
        {
            temp->children[index] = (struct Trie *) calloc(1, sizeof(struct Trie));
        }
        temp = temp->children[index];
    }
    // increment
    temp->flag++;
}

int numberOfOccurrences(struct Trie *pTrie, char *word) 
{  
    // check for NULL
    if(pTrie == NULL)
    {
        return 0;
    }
    struct Trie *temp = pTrie;
    int length = strlen(word);

    // check for amount of occurances
    for (int x = 0; x < length; x++) 
    {
        int index = word[x] - 'a';
        if (temp->children[index] == NULL) 
        {
            return 0;
        }
        temp = temp->children[index];
    }
    return temp->flag;
}

struct Trie *deallocateTrie(struct Trie *pTrie) 
{
    if (pTrie != NULL) 
    {
        // deallocation if trie contains values
        for (int x = 0; x < 26; x++) 
        {
            deallocateTrie(pTrie->children[x]);
        }
    }
    free (pTrie);
    return NULL;
}

int main(void) 
{
    struct Trie *trie = (struct Trie *) calloc(1, sizeof(struct Trie));
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

    // loop to insert function and then display the amount of occurances
    for (int x = 0; x < 5; x++) 
    {
        insert(&trie, pWords[x]);
        printf("\t%s : %d\n", pWords[x], numberOfOccurrences(trie, pWords[x]));
    }
    trie = deallocateTrie(trie);
    if (trie != NULL) 
    {
        printf("There is an error in this program\n");
    }
    return 0;
}