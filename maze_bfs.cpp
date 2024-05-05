#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Coord {
    int row, col;

    Coord(int r, int c) : row(r), col(c) {}
};

bool isValid(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

void printMaze(const vector<vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

bool bfs(vector<vector<char>>& maze, Coord start, Coord destination) {
    const int rows = maze.size();
    const int cols = maze[0].size();

    // Mark the start point as visited
    maze[start.row][start.col] = 'V';

    queue<Coord> q;
    q.push(start);

    while (!q.empty()) {
        Coord current = q.front();
        q.pop();

        if (current.row == destination.row && current.col == destination.col) {
            // Destination reached
            return true;
        }

        // Explore neighbors
        const int dr[] = {-1, 1, 0, 0};  // Up, Down, Left, Right
        const int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];

            if (isValid(newRow, newCol, rows, cols) && (maze[newRow][newCol] == '.' || maze[newRow][newCol] == 'F')) {
                // Mark the cell as visited
                maze[newRow][newCol] = 'V';

                // Enqueue the neighbor for further exploration
                q.push(Coord(newRow, newCol));
            }
        }
    }

    // Destination not reachable
    return false;
}

int main() {
    // Example maze
    vector<vector<char>> maze = {
        {'S', '.', '.', '#', '.', '.', '#', '#'},
        {'.', '#', '.', '.', '.', '#', '.', '.'},
        {'#', '#', '#', '#', '.', '#', '#', '#'},
        {'.', '#', '.', '.', '.', '.', '.', 'F'},
    };

    Coord start(0, 0);
    Coord destination(3, 7);

    cout << "Original Maze:\n";
    printMaze(maze);

    if (bfs(maze, start, destination)) {
        cout << "\nPath Found!\n";
        printMaze(maze);
    } else {
        cout << "\nNo Path Found.\n";
    }

    return 0;
}

