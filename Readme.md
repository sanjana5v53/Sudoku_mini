# Sudoku Solver

## Objective
The objective of this project is to develop a Sudoku solver program that can generate random Sudoku puzzles and solve them using a backtracking algorithm. The program provides a command-line interface to interact with the solver, allowing users to generate and solve Sudoku puzzles.

## Abstract
Sudoku is a popular puzzle game that challenges players to fill a 9x9 grid with digits from 1 to 9, ensuring that each row, column, and 3x3 subgrid contains all the digits exactly once. This project presents a Sudoku solver program implemented in C, capable of generating random Sudoku puzzles and solving them efficiently using backtracking.

The program provides two main modes of operation:
- **Generation Mode:** Generates a random Sudoku puzzle with a predetermined number of filled cells and leaves the rest empty.
- **Solve Mode:** Allows users to input a Sudoku puzzle and attempts to solve it.

The solver employs a backtracking algorithm to systematically explore possible solutions, ensuring that all constraints of the Sudoku puzzle are satisfied.

## Problem Statement
Sudoku is a popular puzzle game consisting of a grid of 9x9 cells, subdivided into 9 regions each containing 3x3 cells. The objective is to fill the grid so that each row, each column, and each of the 9 non-overlapping 3x3 regions contain all of the digits from 1 to 9. A partially completed puzzle is provided with some cells already filled; the task is to fill in the remaining cells such that the completed puzzle follows the rules mentioned above.

## Implementation
This program provides a command-line interface to generate and solve Sudoku puzzles. It uses a backtracking algorithm to solve the puzzles. The program allows two modes of operation:
- **Generation Mode:** Generates a random Sudoku puzzle with some cells initially filled and some cells left empty.
- **Solve Mode:** Allows users to input a Sudoku puzzle and then attempts to solve it.

## Data Structures Used
The main data structure used in this program is a 2D array to represent the Sudoku grid. Each cell of the grid contains an integer value representing the number in that cell. Additionally, arrays and simple variables are used for other purposes like shuffling rows/columns, checking if a number can be placed in a cell, etc.

## Algorithm Used
The program uses a backtracking algorithm to solve Sudoku puzzles. The algorithm works as follows:
1. Find an empty cell in the grid.
2. Try placing numbers from 1 to 9 in the empty cell.
3. Check if the number is safe to place at the current position (i.e., it doesn't violate the rules of Sudoku).
4. If the number is safe, place it in the cell and recursively try to solve the rest of the puzzle.
5. If placing the current number leads to a solution, return true. Otherwise, backtrack and try the next number.
6. If no number can be placed in the current cell, return false.

## Flowchart
```
  Start
    |
    v
  Choose Mode (Generation / Solve)
    |
    v
  Generate Random Sudoku Puzzle
    |
    v
  (Optional) Remove Numbers to Create Partially Filled Puzzle
    |
    v
  Display Generated Puzzle
    |
    v
  (If Solve Mode)
    |
    v
  Input Sudoku Puzzle
    |
    v
  Solve Sudoku Puzzle
    |
    v
  Display Solved Puzzle (if solved)
    |
    v
  End
```

## Results/Output
The Sudoku solver program successfully generates random Sudoku puzzles and solves them within a reasonable amount of time. The output of the program includes:
- The generated Sudoku puzzle (in generation mode).
- The solved Sudoku puzzle (in solve mode), if a solution exists.
- Error messages if the program encounters invalid inputs or fails to solve the puzzle.

## Real-Life Uses
- **Entertainment:** Sudoku puzzles are a popular pastime activity for people of all ages.
- **Mental Exercise:** Solving Sudoku puzzles regularly can help improve cognitive abilities such as logic, critical thinking, and problem-solving skills.
- **Education:** Sudoku puzzles are sometimes used in educational settings to teach concepts related to mathematics, logic, and pattern recognition.
- **Research:** Sudoku solving algorithms can be studied and optimized as part of research in artificial intelligence and optimization techniques.

## Conclusions
The Sudoku solver project demonstrates the effectiveness of backtracking algorithms in solving constraint satisfaction problems such as Sudoku puzzles. The program efficiently generates random Sudoku puzzles and provides solutions that adhere to the rules of the game.

The project also highlights the importance of algorithmic optimization and data structure selection in developing efficient solutions for combinatorial problems. Further enhancements could include implementing additional solving techniques, optimizing the generation process, and improving the user interface for better interaction.

Overall, the Sudoku solver project serves as a practical application of algorithmic problem-solving techniques and contributes to the development of tools for puzzle enthusiasts and educational purposes.