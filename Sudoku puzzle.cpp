#include <iostream>
#include <vector>

#define N 9

using namespace std;

void displayBoard(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << board[row][col] << " ";
        }
        if (row == 2 || row == 5) {
            cout << endl;
            for (int i = 0; i < N; i++)
                cout << "---";
        }
        cout << endl;
    }
}

bool isSafe(int board[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

bool isSolved(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0)
                return false;
        }
    }
    return true;
}

void userInput(int board[N][N]) {
    int row, col, num;
    while (!isSolved(board)) {
        cout << "Enter row (0-8), column (0-8) and number (1-9): ";
        cin >> row >> col >> num;
        
        if (row >= 0 && row < N && col >= 0 && col < N && num >= 1 && num <= 9) {
            if (board[row][col] == 0 && isSafe(board, row, col, num)) {
                board[row][col] = num;
                displayBoard(board);
            } else {
                cout << "Invalid move! Try again." << endl;
            }
        } else {
            cout << "Invalid input! Please enter valid row, column, and number." << endl;
        }
    }
    cout << "Congratulations! You solved the Sudoku puzzle!" << endl;
}

int main() {
    int board[N][N] = {
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

    cout << "Initial Sudoku Board:" << endl;
    displayBoard(board);

    userInput(board);

    return 0;
}
