/*Lynsey Ciaran Ashley*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH 26
#define OPERATION_BUF_SIZE 7
#define NAME_BUF_SIZE 22

#define L_SIZE (OPERATION_BUF_SIZE + NAME_BUF_SIZE + 1)


typedef enum {
        add,
        find,
        search,
        incorrect,
}CommandType;



CommandType getInputValue(char s[]){

        if(strcmp(s, "add") == 0){
                return add;
        }

        if(strcmp(s, "find") == 0){
                return find;
        }


        if(strcmp(s, "search") == 0){
                return search;
        }

        return incorrect;


}
typedef struct node{


        int prefix_count;

        struct node *children[ALPHABET_LENGTH +1];

}trie_node;


trie_node *goDownTrie(char *n, tree_node t){

        int g = 0;


        while(n[g] != '\0'){

                int letter = n[g] - 'a';

                if((*t).children[letter] == NULL){
                        return NULL;
                }
                t = (*t).children[letter];
                j++
        }
        return t;
}

trie_node *goDownTrieCreate(char *n, tree_node t){

        int g = 0;


        while(n[g] != '\0'){

                int letter = n[g] - 'a';

                if((*t).children[letter] == NULL){
                        (*t).children[letter] = calloc(1, sizeof(trie_node));
                }
                t = (*t).children[letter];
                (*t).prefix_count++;
                j++
        }
        return t;
}



addFunction(trie_node *root, char *n){

        trie_node *t = goDownTrieCreate(n, root);


        if((*t).children[ALPHABET_LENGTH] ==NULL){
         (*t).children[ALPHABET_LENGTH] = calloc(1,sizeof(trie_node));
        }

}


findFunction(trie_node *root, char *n){

         trie_node *t = goDownTrie(n, root);

         if(t == NULL){
                return 0;
         }
         return (*t).prefix_count;

}



searchFunction(trie_node *root, char *n){

        trie_node *t = goDownTrie(n, root);

        if(t == NULL){
                return 0;
         }

         return (*t).children[ALPHABET_LENGTH] != NULL;


}


freeEverything(trie_node *t){
        if(t == NULL){
                return;
         }

         int p = 0;

         while(p<=ALPHABET_LENGTH){

                freeEverything((*t).children[p]);

                p++;
         }
         freeEverything(t);


}


int main(void){
        char s[L_SIZE];
        int numCommands;
        int size = sizeof(trie_node);
        trie_node *root = calloc(1, size);

        if(root == NULL){
                return -1;
        }


        fgets(s, sizeof(s), stdin);

        numCommands = atoi(s);


        for(int i=0; i<numCommands; i++){

                fgets(s, sizeof(s), stdin);


                char *command = strtok(s, " \n");
                char *n = strtok(NULL, " \n");


                CommandType in = getInputValue(command);



                switch (in){

                        case add:
                                addFunction(root,n);
                                break;

                        case find:
                                printf("%d\n", findFunction(root, n));
                                break;


                        case search:
                                if(searchFunction(root,n)){
                                        printf("yes\n");
                                }else{
                                        printf("no\n");
                                }
                                break;

                        case incorrect:
                                break;
                }
        }

        return 0;
}