#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
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

bool dfs(const State& initialState, const State& goalState) {
    stack<State> stateStack;
    unordered_set<State, StateHash> visited;

    stateStack.push(initialState);

    while (!stateStack.empty()) {
        State currentState = stateStack.top();
        stateStack.pop();

        if (currentState == goalState) {
            printState(currentState);
            return true;
        }

        visited.insert(currentState);

        vector<State> nextStates;
        const string sides = "LR";

        for (char farmer : sides) {
            for (char wolf : sides) {
                for (char goat : sides) {
                    for (char cabbage : sides) {
                        State nextState = {farmer, wolf, goat, cabbage};

                        if (isValid(nextState) && visited.find(nextState) == visited.end()) {
                            nextStates.push_back(nextState);
                        }
                    }
                }
            }
        }

        for (const State& nextState : nextStates) {
            stateStack.push(nextState);
            visited.insert(nextState);
            printState(nextState);
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

    if (!dfs(initialState, goalState)) {
        cout << "No solution found.\n";
    }

    return 0;
}

