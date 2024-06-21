// Maze size constants
const ROWS = 10;
const COLS = 10;

// Maze representation
let maze = [];

// Player's initial position
let playerRow = 0;
let playerCol = 0;

// Function to initialize the maze
function initializeMaze() {
    maze = [];
    for (let i = 0; i < ROWS; ++i) {
        maze.push(Array(COLS).fill(' '));
    }

    // Generate walls randomly (20% chance)
    for (let i = 0; i < ROWS; ++i) {
        for (let j = 0; j < COLS; ++j) {
            if (Math.random() < 0.2) {
                maze[i][j] = '#';
            }
        }
    }

    // Set start ('S') and exit ('E')
    maze[0][0] = 'S';
    maze[ROWS - 1][COLS - 1] = 'E';

    // Set player ('P') at start position
    playerRow = 0;
    playerCol = 0;
    maze[playerRow][playerCol] = 'P';
}

// Function to print the maze
function printMaze() {
    let output = "";
    for (let i = 0; i < ROWS; ++i) {
        for (let j = 0; j < COLS; ++j) {
            output += maze[i][j] + " ";
        }
        output += "\n";
    }
    console.log(output);
}

// Function to handle player movement
function movePlayer(direction) {
    let newRow = playerRow;
    let newCol = playerCol;

    switch (direction) {
        case 'ArrowUp':
            newRow--;
            break;
        case 'ArrowDown':
            newRow++;
            break;
        case 'ArrowLeft':
            newCol--;
            break;
        case 'ArrowRight':
            newCol++;
            break;
        default:
            console.log("Invalid move! Use arrow keys to move.");
            return;
    }

    // Check if the new position is within bounds and not a wall
    if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] !== '#') {
        // Clear current position
        maze[playerRow][playerCol] = ' ';
        playerRow = newRow;
        playerCol = newCol;
        // Set player at new position
        maze[playerRow][playerCol] = 'P';
    } else {
        console.log("Invalid move! You hit a wall or moved out of bounds.");
    }

    // Check if the player reached the exit
    if (maze[playerRow][playerCol] === 'E') {
        console.log("Congratulations! You found the exit.");
        initializeMaze(); // Restart the game
    }
}

// Function to handle user input
function handleKeyPress(event) {
    movePlayer(event.key);
    printMaze();
}

// Initialize the game
initializeMaze();
printMaze();
console.log("Use arrow keys to move.");

// Event listener for keyboard input
document.addEventListener('keydown', handleKeyPress);
