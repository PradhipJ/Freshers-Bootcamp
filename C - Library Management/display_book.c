#include<stdio.h>
#include "libMacros.h"

void displayOneBook(Book *book){
    printf("Book ID: %d\n", book->id);
    printf("Book Name: %s", book->bookName);
    printf("Author Name: %s", book->authorName);
    printf("Publisher Name: %s", book->publisherName);
    printf("Number of copies: %d\n", book->numCopies);
}