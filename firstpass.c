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






addFunction(){}


findFunction(){}



searchFunction(){}


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



