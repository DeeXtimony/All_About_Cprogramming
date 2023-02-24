#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X';

void display_board() {
    system("clear"); // This clears the console for better user experience
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void player_turn() {
    int choice;
    printf("Player %c, enter the number of the square where you want to place your mark: ", player);
    scanf("%d", &choice);
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        printf("That square is already taken. Try again.\n");
        player_turn();
    } else {
        board[row][col] = player;
    }
}

int check_win() {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    int i;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 (X) - Player 2 (O)\n");
    for (i = 0; i < 9; i++) {
        display_board();
        player_turn();
        if (check_win()) {
            printf("Player %c wins!\n", player);
            return 0;
        }
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
    printf("It's a tie!\n");
    return 0;
}
