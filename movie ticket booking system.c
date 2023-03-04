#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Movie{
    char name[50];
    int hour;
    int minute;
    int seats;
    int available_seats;
    int price;
};

void printMenu(){
    printf("Welcome to Daniels Movie Ticket Booking System\n");
    printf("-------------------------------------\n");
    printf("1. Book ticket\n");
    printf("2. View movie list\n");
    printf("3. Exit\n");
}

void printMovieList(struct Movie *movies, int size){
    printf("Movie List\n");
    printf("----------\n");
    for(int i=0;i<size;i++){
        printf("%d. %s\n",i+1,movies[i].name);
    }
}

void bookTicket(struct Movie *movies, int size){
    int choice;
    printf("Enter the movie number you want to book tickets for: ");
    scanf("%d",&choice);
    if(choice<1 || choice>size){
        printf("Invalid choice\n");
        return;
    }
    struct Movie *movie = &movies[choice-1];
    printf("Movie selected: %s\n",movie->name);
    printf("Available seats: %d\n",movie->available_seats);
    printf("Enter the number of tickets you want to book: ");
    int tickets;
    scanf("%d",&tickets);
    if(tickets>movie->available_seats){
        printf("Not enough seats available\n");
        return;
    }
    printf("Total price: %d\n",tickets*movie->price);
    movie->available_seats -= tickets;
    printf("Tickets booked successfully\n");
}

int main(){
    struct Movie movies[3];
    strcpy(movies[0].name,"Avengers: Endgame");
    movies[0].hour = 18;
    movies[0].minute = 0;
    movies[0].seats = 100;
    movies[0].available_seats = 100;
    movies[0].price = 150;

    strcpy(movies[1].name,"The Dark Knight");
    movies[1].hour = 20;
    movies[1].minute = 30;
    movies[1].seats = 80;
    movies[1].available_seats = 80;
    movies[1].price = 120;

    strcpy(movies[2].name,"Inception");
    movies[2].hour = 22;
    movies[2].minute = 0;
    movies[2].seats = 70;
    movies[2].available_seats = 70;
    movies[2].price = 100;

    while(1){
        printMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                bookTicket(movies,3);
                break;
            case 2:
                printMovieList(movies,3);
                break;
            case 3:
                printf("Thank you for using Movie Ticket Booking System\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
