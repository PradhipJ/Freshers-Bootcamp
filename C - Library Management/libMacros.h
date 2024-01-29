#define SUCCESS 1
#define FAILURE 0
#define MAXBOOKS 1000

typedef struct bookStruct {
    int id;
    char bookName[20];
    char authorName[20];
    char publisherName[20];
    int numCopies;
} Book;

extern void displayOneBook(Book *book);
extern void displayAllBooks(Book *books, int *numOfBooks);
extern Book* searchBook(Book *books, char *name, int *numOfBooks);
extern int addBook(Book *books, int *last);
extern int issueBook(Book *books, char *name, int *numOfBooks);
extern int returnBook(Book *books, char *name, int *numOfBooks);
extern int deleteBook(Book *books, char *name, int *numOfBooks);