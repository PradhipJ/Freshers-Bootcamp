#include <stdio.h>
#include <string.h>
#include "libMacros.h"

void displayAllBooks(Book *books, int *numOfBooks){
    for(int i = 0; i < *numOfBooks; i++){
        printf("Book ID: %d\n", (books+i)->id);
        printf("Book Name: %s", (books+i)->bookName);
        printf("Author Name: %s", (books+i)->authorName);
        printf("Publisher Name: %s", (books+i)->publisherName);
        printf("Number of copies: %d\n", (books+i)->numCopies);
    }
}