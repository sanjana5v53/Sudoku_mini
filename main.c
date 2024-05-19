#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}

// Function to check if a given number is safe to place at a given position
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is not already present in the row, column, or 3x3 grid
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num ||
            grid[row - row % 3 + i / 3][col - col % 3 + i % 3] == num)
            return false;
    }
    return true;
}

// Function to solve the Sudoku puzzle
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Find an empty cell in the grid
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }

    // If no empty cell is found, the puzzle is solved
    if (!isEmpty) return true;

    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively try to solve the puzzle
            if (solveSudoku(grid)) return true;

            // If placing the current number doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // If no number can be placed in the current cell, backtrack
    return false;
}

// Function to shuffle the rows of the Sudoku grid
void shuffleRows(int grid[N][N]) {
    for (int i = 0; i < N; i += 3) {
        int randRow = rand() % 3;
        for (int j = 0; j < 3; j++) {
            int temp[N];
            memcpy(temp, grid[i + j], sizeof(temp));
            memcpy(grid[i + j], grid[i + randRow], sizeof(temp));
            memcpy(grid[i + randRow], temp, sizeof(temp));
        }
    }
}

// Function to shuffle the columns of the Sudoku grid
void shuffleCols(int grid[N][N]) {
    for (int i = 0; i < N; i += 3) {
        int randCol = rand() % 3;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < N; k++) {
                int temp = grid[k][i + j];
                grid[k][i + j] = grid[k][i + randCol];
                grid[k][i + randCol] = temp;
            }
        }
    }
}

// Function to generate a random Sudoku puzzle
void generateRandomSudoku(int grid[N][N]) {
    // Seed the random number generator
    srand(time(NULL));

    // Solve a completed Sudoku puzzle
    solveSudoku(grid);

    // Shuffle rows and columns to create a random puzzle
    shuffleRows(grid);
    shuffleCols(grid);

    // Remove some numbers to create a partially filled puzzle
    int numToRemove = rand() % 30 + 30; // Remove 30 to 59 numbers
    while (numToRemove > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            numToRemove--;
        }
    }
}

// Driver function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <gen|solve>\n", argv[0]);
        return 1;
    }

    int grid[N][N] = {0}; // Initialize the grid with zeros

    if (strcmp(argv[1], "gen") == 0) {
        generateRandomSudoku(grid);
        printf("Generated Sudoku Puzzle:\n");
        printGrid(grid);
    } else if (strcmp(argv[1], "solve") == 0) {
        printf("Enter the Sudoku puzzle:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        printf("\nSolving Sudoku Puzzle:\n");
        if (solveSudoku(grid))
            printGrid(grid);
        else
            printf("No solution exists");
    } else {
        printf("Invalid argument: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
