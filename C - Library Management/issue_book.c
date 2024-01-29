#include <stdio.h>
#include <string.h>
#include "libMacros.h"

int issueBook(Book *books, char *name, int *numOfBooks){
    for(int i = 0; i < *numOfBooks; i++){
        if(strcmp(name, (books+i)->bookName) == 0){
            if((books+i)->numCopies == 0) return FAILURE;
            (books+i)->numCopies -= 1;
            return SUCCESS;
        }
    }
    return FAILURE;
}