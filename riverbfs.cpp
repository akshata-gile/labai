#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

struct State {
    char farmer, wolf, goat, cabbage;

    bool operator==(const State& other) const {
        return farmer == other.farmer && wolf == other.wolf && goat == other.goat && cabbage == other.cabbage;
    }
};

struct StateHash {
    size_t operator()(const State& state) const {
        return hash<string>()(to_string(state.farmer) + to_string(state.wolf) + to_string(state.goat) + to_string(state.cabbage));
    }
};

bool isValid(const State& state) {
    if ((state.wolf == state.goat && state.farmer != state.wolf) || (state.goat == state.cabbage && state.farmer != state.goat)) {
        return false;
    }
    return true;
}

void printState(const State& state) {
    cout << "Farmer: " << state.farmer << ", Wolf: " << state.wolf << ", Goat: " << state.goat << ", Cabbage: " << state.cabbage << endl;
}

vector<State> generateNextStates(const State& currentState) {
    vector<State> nextStates;
    const string sides = "LR";

    for (char farmer : sides) {
        for (char wolf : sides) {
            for (char goat : sides) {
                for (char cabbage : sides) {
                    State nextState = {farmer, wolf, goat, cabbage};

                    if (isValid(nextState)) {
                        nextStates.push_back(nextState);
                    }
                }
            }
        }
    }

    return nextStates;
}

bool bfs(const State& initialState, const State& goalState) {
    queue<State> q;
    unordered_set<State, StateHash> visited;

    q.push(initialState);
    visited.insert(initialState);

    while (!q.empty()) {
        State currentState = q.front();
        q.pop();

        if (currentState == goalState) {
            printState(currentState);
            return true;
        }

        vector<State> nextStates = generateNextStates(currentState);
        for (const State& nextState : nextStates) {
            if (visited.find(nextState) == visited.end()) {
                visited.insert(nextState);
                q.push(nextState);
                printState(nextState);
            }
        }
    }

    return false;
}

int main() {
    // Initial state: Farmer, Wolf, Goat, Cabbage on the left side
    State initialState = {'L', 'L', 'L', 'R'};
    // Goal state: Farmer, Wolf, Goat, Cabbage on the right side
    State goalState = {'R', 'R', 'R', 'R'};

    cout << "Initial State:\n";
    printState(initialState);

    if (!bfs(initialState, goalState)) {
        cout << "No solution found.\n";
    }

    return 0;
}

