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
