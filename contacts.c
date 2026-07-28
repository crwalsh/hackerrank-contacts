/*
 * Contacts trie solution
 * Team member: Ciaran Walsh
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_LENGTH    26
#define OPERATION_BUF_SIZE  7 /* Large enough to cover the word 'search' and '\0' */
#define NAME_BUF_SIZE      22

/* Basic trie node */
typedef struct node {
    /* The number of words in the trie that contain the prefix down to and
       including the current letter. */
    int prefix_count;
    /* Allocate +1 for the the pointer to the end-of-string marker. Needed
       for the search feature. */
    struct node *children[ALPHABET_LENGTH + 1];
} trie_node;

/*
 * A shared sentinel marks the end of every stored word. Since the program
 * never dereferences this node, one sentinel avoids an allocation per word.
 */
static trie_node end_marker;

/* Allocate a zero-initialized trie node. */
static trie_node *create_node(void)
{
    return calloc(1, sizeof(trie_node));
}

/*
 * Add word to the trie. Each add operation increases the prefix counts,
 * including when the same word is added more than once.
 */
static bool add(trie_node *root, const char *word)
{
    trie_node *current = root;

    while (*word != '\0') {
        int index = *word - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = create_node();
            if (current->children[index] == NULL) {
                return false;
            }
        }

        current = current->children[index];
        current->prefix_count++;
        word++;
    }

    current->children[ALPHABET_LENGTH] = &end_marker;
    return true;
}

/* Return the number of stored names that begin with prefix. */
static int find(const trie_node *root, const char *prefix)
{
    const trie_node *current = root;

    while (*prefix != '\0') {
        int index = *prefix - 'a';

        if (current->children[index] == NULL) {
            return 0;
        }

        current = current->children[index];
        prefix++;
    }

    return current->prefix_count;
}

/* Return true only when the complete word, rather than just a prefix, exists. */
static bool search(const trie_node *root, const char *word)
{
    const trie_node *current = root;

    while (*word != '\0') {
        int index = *word - 'a';

        if (current->children[index] == NULL) {
            return false;
        }

        current = current->children[index];
        word++;
    }

    return current->children[ALPHABET_LENGTH] != NULL;
}

/* Recursively release all allocated letter nodes, but not the shared marker. */
static void free_trie(trie_node *root)
{
    int index;

    if (root == NULL) {
        return;
    }

    for (index = 0; index < ALPHABET_LENGTH; index++) {
        free_trie(root->children[index]);
    }
    free(root);
}

int main(void)
{
    int operation_count;
    int operation_index;
    char operation[OPERATION_BUF_SIZE];
    char name[NAME_BUF_SIZE];
    trie_node *root = create_node();

    if (root == NULL) {
        return EXIT_FAILURE;
    }

    if (scanf("%d", &operation_count) != 1) {
        free_trie(root);
        return EXIT_FAILURE;
    }

    for (operation_index = 0; operation_index < operation_count;
         operation_index++) {
        if (scanf("%6s %21s", operation, name) != 2) {
            free_trie(root);
            return EXIT_FAILURE;
        }

        if (strcmp(operation, "add") == 0) {
            if (!add(root, name)) {
                free_trie(root);
                return EXIT_FAILURE;
            }
        } else if (strcmp(operation, "find") == 0) {
            printf("%d\n", find(root, name));
        } else if (strcmp(operation, "search") == 0) {
            puts(search(root, name) ? "yes" : "no");
        }
    }

    free_trie(root);
    return EXIT_SUCCESS;
}
