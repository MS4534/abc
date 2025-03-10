#include <stdio.h>

#include <stdbool.h>

#define N 8 // You can change this to solve for different board sizes

// Function to print the board

void printBoard(int board[N][N]) {

for (int i = 0; i < N; i++) {

for (int j = 0; j < N; j++)

printf(" %d ", board[i][j]);

printf("\n");

}

}

// Function to check if a queen can be placed on board[row][col]

bool isSafe(int board[N][N], int row, int col) {

int i, j;

// Check this row on left side

for (i = 0; i < col; i++)

if (board[row][i])

return false;

// Check upper diagonal on left side

for (i = row, j = col; i >= 0 && j >= 0; i--, j--)

if (board[i][j])

return false;

// Check lower diagonal on left side

for (i = row, j = col; i < N && j >= 0; i++, j--)

if (board[i][j])

return false;

return true;

}

// A recursive utility function to solve N Queen problem

bool solveNQUtil(int board[N][N], int col) {

// If all queens are placed, return true

if (col >= N)

return true;

// Consider this column and try placing this queen in all rows one by one

for (int i = 0; i < N; i++) {

if (isSafe(board, i, col)) {

// Place this queen in board[i][col]

board[i][col] = 1;
// Recur to place the rest of the queens

if (solveNQUtil(board, col + 1))

return true;

// If placing queen in board[i][col] doesn't lead to a solution

// then remove queen from board[i][col] (backtrack)

board[i][col] = 0;

}

}

// If the queen cannot be placed in any row in this column, return false

return false;

}

// This function solves the N Queen problem using Backtracking

// It mainly uses solveNQUtil() to solve the problem

bool solveNQ() {

int board[N][N] = {0};

if (!solveNQUtil(board, 0)) {

printf("Solution does not exist");

return false;

}

printBoard(board);

return true;

}

// Driver program to test the above functions

int main() {

solveNQ();

return 0;

}
