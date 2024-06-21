#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constants for maze size
const int ROWS = 10;
const int COLS = 10;

// Function to print the maze
void printMaze(const vector<vector<char>>& maze) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to generate the maze
void generateMaze(vector<vector<char>>& maze) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Generate walls randomly (20% chance)
            if (rand() % 100 < 20) {
                maze[i][j] = '#'; // '#' represents a wall
            } else {
                maze[i][j] = ' '; // ' ' represents an empty space
            }
        }
    }
    // Set the starting point and exit
    maze[0][0] = 'S'; // 'S' represents the starting point
    maze[ROWS - 1][COLS - 1] = 'E'; // 'E' represents the exit
}

// Function to move the player in the maze
bool movePlayer(vector<vector<char>>& maze, int& playerRow, int& playerCol, char move) {
    int newRow = playerRow;
    int newCol = playerCol;

    switch(move) {
        case 'W': // Move up
        case 'w':
            newRow--;
            break;
        case 'S': // Move down
        case 's':
            newRow++;
            break;
        case 'A': // Move left
        case 'a':
            newCol--;
            break;
        case 'D': // Move right
        case 'd':
            newCol++;
            break;
        default:
            cout << "Invalid move! Use W (up), S (down), A (left), D (right)." << endl;
            return false;
    }

    // Check if the new position is within bounds and not a wall
    if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] != '#') {
        maze[playerRow][playerCol] = ' '; // Clear current position
        playerRow = newRow;
        playerCol = newCol;
        maze[playerRow][playerCol] = 'P'; // 'P' represents the player
        return true;
    } else {
        cout << "Invalid move! You hit a wall or moved out of bounds." << endl;
        return false;
    }
}

int main() {
    vector<vector<char>> maze(ROWS, vector<char>(COLS));
    srand(static_cast<unsigned>(time(0)));

    // Generate maze and initialize player position
    generateMaze(maze);
    int playerRow = 0;
    int playerCol = 0;
    maze[playerRow][playerCol] = 'P'; // 'P' represents the player

    // Game loop
    while (maze[playerRow][playerCol] != 'E') {
        printMaze(maze);
        cout << "Enter your move (W, A, S, D): ";
        char move;
        cin >> move;

        // Move the player based on user input
        movePlayer(maze, playerRow, playerCol, move);
    }

    // Player reached the exit
    cout << "Congratulations! You found the exit." << endl;

    return 0;
}
