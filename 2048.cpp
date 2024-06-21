#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Size of the board
const int SIZE = 4;

// Function to print the board
void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to initialize the board with zeros
void initializeBoard(vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        vector<int> row(SIZE, 0);
        board.push_back(row);
    }
}

// Function to add a random tile (2 or 4) to the board
void addRandomTile(vector<vector<int>>& board) {
    vector<pair<int, int>> emptyCells;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                emptyCells.push_back(make_pair(i, j));
            }
        }
    }
    if (emptyCells.empty()) return;

    srand(static_cast<unsigned>(time(0)));
    int randomIndex = rand() % emptyCells.size();
    int value = (rand() % 2 + 1) * 2; // Generates either 2 or 4 randomly
    board[emptyCells[randomIndex].first][emptyCells[randomIndex].second] = value;
}

// Function to check if the board is full
bool isBoardFull(vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Main function to play the game
int main() {
    vector<vector<int>> board;
    initializeBoard(board);
    addRandomTile(board);
    addRandomTile(board);
    printBoard(board);

    while (!isBoardFull(board)) {
        // Implement game logic here based on user input
        // Example: Take input from user (e.g., W, A, S, D for up, left, down, right)
        // Update board, add random tile, print board, and continue until game over
    }

    cout << "Game Over!" << endl;

    return 0;
}
