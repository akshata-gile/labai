#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Structure to represent coordinates in the maze
struct Coord {
    int row, col;

    Coord(int r, int c) : row(r), col(c) {}
};

// Function to print the maze
void printMaze(const vector<vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if a coordinate is valid in the maze
bool isValid(const vector<vector<char>>& maze, const vector<vector<bool>>& visited, int row, int col) {
    return row >= 0 && row < maze.size() && col >= 0 && col < maze[0].size() && maze[row][col] != '#' && !visited[row][col];
}

// Depth-First Search to solve the maze problem
bool dfs(vector<vector<char>>& maze, const Coord& start, const Coord& exit) {
    stack<Coord> s;
    s.push(start);

    // Create a visited array to keep track of visited cells
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));

    while (!s.empty()) {
        Coord current = s.top();
        s.pop();

        // If the exit is reached, print the solution and return true
        if (current.row == exit.row && current.col == exit.col) {
            maze[current.row][current.col] = 'F'; // Mark the exit cell
            printMaze(maze);
            return true;
        }

        // Mark the current cell as visited
        maze[current.row][current.col] = 'o';
        visited[current.row][current.col] = true;

        // Explore neighbors in four directions: up, right, down, left
        int directions[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (const auto& dir : directions) {
            int newRow = current.row + dir[0];
            int newCol = current.col + dir[1];

            // Check if the neighbor is valid and not visited
            if (isValid(maze, visited, newRow, newCol)) {
                s.push(Coord(newRow, newCol));
            }
        }
    }

    // No path to the exit found
    cout << "No solution found." << endl;
    return false;
}

int main() {
    // Example maze (you can customize this maze)
    vector<vector<char>> maze = {
        {'S', ' ', ' ', '#', ' ', ' ', ' '},
        {'#', '#', ' ', '#', ' ', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', '#', ' ', '#', '#', '#', ' '},
        {'#', ' ', ' ', ' ', ' ', ' ', 'F'}
    };

    Coord start(0, 0);
    Coord exit(maze.size() - 1, maze[0].size() - 1);

    cout << "Maze:\n";
    printMaze(maze);

    cout << "\nSolution Path:\n";
    dfs(maze, start, exit);

    return 0;
}

