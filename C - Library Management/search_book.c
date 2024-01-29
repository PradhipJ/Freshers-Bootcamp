#include <stdio.h>
#include <string.h>
#include "libMacros.h"

Book* searchBook(Book *books, char *name, int *numOfBooks){
    for(int i = 0; i < *numOfBooks; i++){
        if(strcmp(name, (books+i)->bookName) == 0){
            Book *res = books+i;
            return res;
        }
    }
    return NULL;
}