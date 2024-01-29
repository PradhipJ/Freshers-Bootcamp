#include <stdio.h>
#include <string.h>
#include "libMacros.h"

int deleteBook(Book *books, char *name, int *numOfBooks){
    int isDeleted = 0;
    for(int i = 0; i < *numOfBooks; i++){
        if(strcmp(name, (books+i)->bookName) == 0){
            while(i < *numOfBooks - 1){
                books[i]= books[i + 1];
                i++;
            }
            isDeleted = 1;
            break;
        }
    }
    if(isDeleted){
        *numOfBooks -= 1;
        return SUCCESS;
    }
    return FAILURE;
}