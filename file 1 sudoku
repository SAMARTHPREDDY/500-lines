#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Predefined Sudoku puzzle (0 represents empty cells)
int grid[SIZE][SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// Function to display the grid
void displayGrid() {
    printf("Sudoku Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Check if placing a number is valid
bool isValid(int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

// Input a number into the grid
void inputNumber() {
    int row, col, num;
    printf("Enter row (0-8), column (0-8), and number (1-9): ");
    scanf("%d %d %d", &row, &col, &num);

    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && isValid(row, col, num)) {
        grid[row][col] = num;
    } else {
        printf("Invalid input. Try again.\n");
    }
}

// Check if the grid is fully solved
bool isSolved() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main() {
    printf("Welcome to Sudoku!\n");
    while (!isSolved()) {
        displayGrid();
        inputNumber();
    }
    printf("Congratulations! You solved the Sudoku!\n");
    return 0;
}
\\
Sudoku, as we know it today, has a fascinating history that spans centuries and involves contributions from various cultures and individuals. Here's a brief overview:

1. Origins in Latin Squares (18th Century)
The roots of Sudoku can be traced back to Latin squares, a concept developed by Swiss mathematician Leonhard Euler in the late 18th century.
A Latin square is a grid where each symbol appears exactly once in each row and column.
Euler's work laid the foundation for the logical structure of Sudoku but did not include the 3x3 subgrid constraint seen in modern Sudoku.
2. 19th-Century French Puzzle Variants
In the late 19th century, similar grid-based puzzles appeared in French newspapers, such as Le Siècle and La France.
These puzzles featured partially filled grids with numbers, similar to Sudoku, but they did not yet have the 3x3 subgrid requirement.
3. Development of Modern Sudoku (1970s)
The modern form of Sudoku, including the 9x9 grid with 3x3 subgrids, was first designed by Howard Garns, an American architect and puzzle enthusiast.
His puzzle, originally called "Number Place," was published in 1979 by Dell Magazines in the United States.
4. Popularization in Japan (1980s)
The puzzle gained widespread popularity after being introduced to Japan in 1984 by Maki Kaji, the founder of the Japanese puzzle company Nikoli.
Nikoli renamed the puzzle Sudoku, short for "Sūji wa dokushin ni kagiru" (数字は独身に限る), which means "the digits must remain single" (i.e., unique in each row, column, and subgrid).
Nikoli also added some key rules, such as limiting the number of given clues and ensuring a unique solution, which enhanced the puzzle's appeal.
5. Global Explosion (2000s)
Sudoku became a global phenomenon in the early 2000s, thanks to Wayne Gould, a retired Hong Kong judge who developed a computer program to generate Sudoku puzzles.
Gould persuaded newspapers around the world, starting with The Times in London (2004), to publish Sudoku puzzles regularly.
The puzzle's simplicity and accessibility contributed to its massive popularity, and it quickly became a staple in newspapers, books, and mobile apps.
Fun Fact:
Sudoku does not rely on language or cultural knowledge, which makes it universally appealing and playable by people worldwide.
Today, Sudoku is a beloved pastime and has inspired countless variations and competitive events!
//
