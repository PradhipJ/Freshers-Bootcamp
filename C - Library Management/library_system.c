#include <stdio.h>
#include <string.h>
#include "libMacros.h"

int main() {
    int currentNumberOfBooks = 0;
    int *numBooks = &currentNumberOfBooks; 
    Book books[MAXBOOKS]; 
    
    printf("LIBRARY MANAGEMENT SYSTEM\n");
    printf("1. Add a book\n");
    printf("2. Display all book details\n");
    printf("3. Search for a book\n");
    printf("4. Issue a book\n");
    printf("5. Return a book\n");
    printf("6. Delete a book\n");
    printf("0. EXIT\n");
    
    int choice = 1;
    while(choice){
        printf("\nChoose an operation to be performed:");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                if(addBook(books, numBooks)) printf("Book added\n");
                else printf("Book can not be added\n");
                break;
            case 2:
                displayAllBooks(books, numBooks);
                break;
            case 3:
                char searchBookName[20];
                printf("Enter book to be searched: ");
                fgets(searchBookName, 20, stdin);
                Book *res = searchBook(books, searchBookName, numBooks);
                if(res != NULL) displayOneBook(res);
                else printf("Book not found\n");
                break;
            case 4:
                char issueBookName[20];
                printf("Enter book to be issued: ");
                fgets(issueBookName, 20, stdin);
                if(issueBook(books, issueBookName, numBooks))
                    printf("Book issued\n");
                else printf("Book can not be issued\n");
                break;
            case 5:
                char returnBookName[20];
                printf("Enter book to be returned: ");
                fgets(returnBookName, 20, stdin);
                if(returnBook(books, returnBookName, numBooks))
                    printf("Book returned\n");
                else printf("Book can not be returned\n");
                break;
            case 6:
                char deleteBookName[20];
                printf("Enter book to be deleted: ");
                fgets(deleteBookName, 20, stdin);
                if(deleteBook(books, deleteBookName, numBooks))
                    printf("Book deleted\n");
                else printf("Book can not be deleted\n");
                break;
            default:
                printf("Invalid operation selected!\n");
                break;
        }
    }
}