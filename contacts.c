#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH    26
#define OPERATION_BUF_SIZE  7 /* Large enough to cover the word 'search' and '\0' */
#define NAME_BUF_SIZE      22


typedef struct node {
    /* The number of words in the trie that contain the prefix down to and
       including the current letter. */
    int prefix_count;
    /* Allocate +1 for the the pointer to the end-of-string marker. Needed
       for the search feature. */
    struct node *children[ALPHABET_LENGTH + 1];
} trie_node;

void add(trie_node *trie, char* word) {
    trie_node *currentnode = trie; 
    while(*word) {
        int index = *word++ - 'a';
        if(!currentnode->children[index]) {
            currentnode->children[index] = calloc(1, sizeof(trie_node));
        }
        currentnode = currentnode->children[index];
        currentnode->prefix_count ++; 
    }
    if (currentnode->children[ALPHABET_LENGTH] == NULL) {
        currentnode->children[ALPHABET_LENGTH] = calloc(1, sizeof(trie_node));
    }
}

int find(trie_node *trie, char *prefix) {
    trie_node *currentnode = trie; 
    while(*prefix) {
        int index = *prefix++ - 'a';
        if(currentnode->children[index] == NULL) {
            return 0; 
        }
        currentnode = currentnode->children[index];
    }
    return currentnode->prefix_count;
}

bool search(trie_node *trie, char *word) {
    trie_node *currentnode = trie; 
    while(*word) {
        int index = *word++ - 'a';
        if(currentnode->children[index] == NULL) {
            return 0; 
        }
        currentnode = currentnode->children[index];
    }
    if(currentnode->children[ALPHABET_LENGTH]) {
        return 1; 
    }
    return 0;
}

void freetrie(trie_node *root) {
    if(root == NULL) {
        return; 
    }
    for(int i = 0; i < ALPHABET_LENGTH + 1; i++) {
        freetrie(root->children[i]);
    }
    free(root);
}

int main() {
    int lines;
    scanf("%d", &lines);
    trie_node *root = calloc(1, sizeof(trie_node));
    char operation[OPERATION_BUF_SIZE]; 
    char name[NAME_BUF_SIZE];
    for(int i = 0; i < lines; i++) {
        scanf("%s %s", operation, name);
        if(strcmp(operation, "add") == 0) {
            add(root, name);
        }
        else if(strcmp(operation, "search") == 0) {
            printf("%d\n", search(root, name));
        }
        else {
            printf("%d\n", find(root, name));
        }
    }
    freetrie(root);
    return 0; 
}

