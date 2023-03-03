#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000

struct Book {
    char title[100];
    char author[50];
    int book_id;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int num_books;
};

void display_menu() {
    printf("\nLIBRARY MANAGEMENT SYSTEM\n");
    printf("1. Add Book\n");
    printf("2. Display All Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
}

void add_book(struct Library *lib) {
    struct Book book;
    printf("\nEnter Title: ");
    scanf("%s", book.title);
    printf("Enter Author: ");
    scanf("%s", book.author);
    printf("Enter Book ID: ");
    scanf("%d", &book.book_id);
    lib->books[lib->num_books] = book;
    lib->num_books++;
    printf("Book added successfully.\n");
}

void display_books(struct Library lib) {
    if (lib.num_books == 0) {
        printf("\nNo books available.\n");
        return;
    }
    printf("\nBook ID\tTitle\t\tAuthor\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < lib.num_books; i++) {
        printf("%d\t%s\t\t%s\n", lib.books[i].book_id, lib.books[i].title, lib.books[i].author);
    }
}

void search_book(struct Library lib) {
    int book_id;
    printf("\nEnter Book ID: ");
    scanf("%d", &book_id);
    for (int i = 0; i < lib.num_books; i++) {
        if (lib.books[i].book_id == book_id) {
            printf("\nBook ID\tTitle\t\tAuthor\n");
            printf("------------------------------------------------------------\n");
            printf("%d\t%s\t\t%s\n", lib.books[i].book_id, lib.books[i].title, lib.books[i].author);
            return;
        }
    }
    printf("\nBook not found.\n");
}

void delete_book(struct Library *lib) {
    int book_id, i;
    printf("\nEnter Book ID: ");
    scanf("%d", &book_id);
    for (i = 0; i < lib->num_books; i++) {
        if (lib->books[i].book_id == book_id) {
            break;
        }
    }
    if (i == lib->num_books) {
        printf("\nBook not found.\n");
        return;
    }
    for (int j = i; j < lib->num_books - 1; j++) {
        lib->books[j] = lib->books[j + 1];
    }
    lib->num_books--;
    printf("\nBook deleted successfully.\n");
}

int main() {
    struct Library lib;
    lib.num_books = 0;
    int choice;
    while (1) {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_book(&lib);
                break;
            case 2:
                display_books(lib);
                break;
            case 3:
                search_book(lib);
                break;
            case 4:
                delete_book(&lib);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}
