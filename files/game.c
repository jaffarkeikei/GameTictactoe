#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define ROWS 3 // The number of rows in the board
#define COLS 3 // The number of columns in the board

char board[ROWS][COLS]; // The board

void initBoard() { // Initialize the board
    int i, j; // Loop variables
    for (i = 0; i < ROWS; i++) { // Loop through the rows
        for (j = 0; j < COLS; j++) { // Loop through the columns
            board[i][j] = ' '; // Set the value to a space
        } 
    }
}   

// Print the board
void printBoard() {
    int i, j;  // Loop variables
    putchar('\n');   // Print a new line
    for (i = 0; i < ROWS; i++) { 
        for (j = 0; j < COLS; j++) { // Loop through the columns
            printf(" %c ", board[i][j]);   
            if (j != COLS - 1) {    // If we are not at the end of the row
                printf("|");   // Print a vertical bar
            }
        }
        if (i != ROWS - 1) {   // If we are not at the end of the column
            printf("\n---+---+---\n"); // Print a horizontal bar
        } 
    }
    printf("\n"); // Print a new line
}

// Check if the player has won
int checkWin(char player) { 
    int i;  // Loop variable
    // check rows
    // if we get here, no one has won yet
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // check columns 
    // if we get here, no one has won yet
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // if we get here, no one has won yet
    // check the current diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    // check the other diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    // if we get here, no one has won yet
    return 0;
}



int main() {
    int i, x, y;  // Loop variable and coordinates
    char player = 'X'; // The current player
    initBoard(); // Initialize the board
    for (i = 0; i < ROWS * COLS; i++) { // Loop through the number of moves
        printBoard(); // Print the board
        printf("Player %c: enter row (0-2), press ENTER then enter column (0-2): ", player);
        if (scanf("%d%d", &x, &y) != 2) {
            char c;
            while ((c = getchar()) != EOF && c != '\n') {} 
        } // Read in the coordinates as integers
        if (x < 0 || x >= ROWS || y < 0 || y >= COLS || !isdigit(x) || !isdigit(y)) {
            printf("Invalid move, try again\n"); // Print an error message
            i--; // Decrement i so that we don't count this move
            continue;
        }
        if (board[x][y] != ' ') { // If the space is not empty
            printf("Invalid move, try again\n"); // Print an error message
            i--; // Decrement i so that we don't count this move
            continue; // Go to the next iteration of the loop
        }

        // If we get here, the move is valid
        board[x][y] = player;

        //after each move, check if the player has won
        if (checkWin(player)) { // If the player has won
            printf("Player %c wins!\n", player); // Print a message
            return 0; // Successful termination
        }
        
        // If we get here, the player has not won
        if (player == 'X') { // If the current player is X
            player = 'O'; // Change the player to O
            } else { 
            player = 'X'; 
            }
        }
        // If we get here, it's a tie
        printf("It's a tie!\n"); // Print a message
        return 0; // successful termination
        }
