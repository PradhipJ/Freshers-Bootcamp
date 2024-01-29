#include<stdio.h>
#include "libMacros.h"

int addBook(Book *books, int *last){
    if(*last >= MAXBOOKS) return FAILURE;
    Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    getchar();
    printf("Enter Book Name: ");
    fgets(newBook.bookName, 20, stdin);
    printf("Enter Author Name: ");
    fgets(newBook.authorName, 20, stdin);
    printf("Enter Publisher Name: ");
    fgets(newBook.publisherName, 20, stdin);
    printf("Enter Number of Copies: ");
    scanf("%d", &newBook.numCopies);
    getchar();
    books[*last] = newBook;
    *last = *last + 1;
    return SUCCESS;
}