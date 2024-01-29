#include <stdio.h>
#include <string.h>
#include "libMacros.h"

int returnBook(Book *books, char *name, int *numOfBooks){
    for(int i = 0; i < *numOfBooks; i++){
        if(strcmp(name, (books+i)->bookName) == 0){
            (books+i)->numCopies += 1;
            return SUCCESS;
        }
    }
    return FAILURE;
}