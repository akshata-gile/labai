#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int checkGameBoard(int size, vector<string>& gb, int ms[], string u, string x); // Declaration of checkGameBoard

void printGameBoard(int size, vector<string>& gb, int ms[], string u1, string u2) {
    int c = 0;
    cout << "Game Board : \n";
    for (int i = 0; i < size; i++) {
        cout << " | " << gb[i] << " | ";
        if (i == size / 3 - 1 || i == size / 3 * 2 - 1 || i == size - 1)
            cout << "\n--------------------\n";
        if (gb[i] == "X" || gb[i] == "O")
            c++;
    }
    if (c == 9) {
        cout << "\n";
        int result_user = checkGameBoard(size, gb, ms, u1, u2);
        int result_comp = checkGameBoard(size, gb, ms, u2, u1);
        if (result_user == -1) {
            cout << "*_* " << u1 << " is the Winner  :)\n";
            exit(0);
        } else if (result_comp == -1) {
            cout << "*_* " << u2 << " is the Winner  :)\n";
            exit(0);
        } else {
            cout << "-------- TIE --------\n";
            exit(0);
        }
    }
}

void computerTurn(int size, vector<string>& gb, string u1, int ms[], string u2) {
    int c = 0, flag = 0;
    for (int i = 0; i < size; i++) {
        if (gb[i] == u1)
            c++;
    }
    if (c == 1) {
        for (int i = size - 1; i >= 0; i--) {
            if (gb[i] != u1) {
                gb[i] = u2;
                break;
            }
        }
    } else {
        int result_user = checkGameBoard(size, gb, ms, u1, u2);
        int result_comp = checkGameBoard(size, gb, ms, u2, u1);
        if (result_user == -1) {
            cout << "*_* " << u1 << " is the Winner --------- 1 :)\n";
            cout << "User : \n";
            printGameBoard(size, gb, ms, u1, u2);
            exit(0);
        } else if (result_comp == -1) {
            cout << "*_* " << u2 << " is the Winner --------- 2 :)\n";
            flag = 1;
        } else if (result_comp != -2 && (gb[result_comp] != u1)) {
            gb[result_comp] = u2;
            cout << "*_* " << u2 << " is the winner --------- 3 :)\n";
            flag = 1;
        } else if (result_user != -2) {
            gb[result_user] = u2;
        } else {
            for (int i = size - 1; i >= 0; i--) {
                if ((gb[i] != u1) && (gb[i] != u2)) {
                    gb[i] = u2;
                    break;
                }
            }
        }
    }
    cout << "Computer : \n";
    printGameBoard(size, gb, ms, u1, u2);
    if (flag == 1)
        exit(0);
}

int checkGameBoard(int size, vector<string>& gb, int ms[], string u, string x) {
    for (int i = 0; i < 3; i++) {
        if ((gb[i] == gb[i + 3]) && (gb[i + 3] == gb[i + 6]) && (gb[i + 6] == u) && ((ms[i] + ms[i + 3] + ms[i + 6]) == 15))
            return -1;
    }
    for (int i = 0; i < size; i += 3) {
        if ((gb[i] == gb[i + 1]) && (gb[i + 1] == gb[i + 2]) && (gb[i + 2] == u) && ((ms[i] + ms[i + 1] + ms[i + 2]) == 15))
            return -1;
    }
    if ((gb[0] == gb[4]) && (gb[4] == gb[8]) && (gb[8] == u) && ((ms[0] + ms[4] + ms[8]) == 15))
        return -1;
    if ((gb[2] == gb[4]) && (gb[4] == gb[6]) && (gb[6] == u) && ((ms[2] + ms[4] + ms[6]) == 15))
        return -1;
    for (int i = 0; i < 3; i++) {
        if ((gb[i] == gb[i + 3]) && (gb[i + 3] == u) && (gb[i + 6] != x))
            return (i + 6);
        if ((gb[i + 3] == gb[i + 6]) && (gb[i + 6] == u) && (gb[i] != x))
            return i;
        if ((gb[i] == gb[i + 6]) && (gb[i + 6] == u) && (gb[i + 3] != x))
            return (i + 3);
    }
    for (int i = 0; i < 8; i += 3) {
        if ((gb[i] == gb[i + 1]) && (gb[i + 1] == u) && (gb[i + 2] != x))
            return (i + 2);
        if ((gb[i + 1] == gb[i + 2]) && (gb[i + 2] == u) && (gb[i] != x))
            return i;
        if ((gb[i] == gb[i + 2]) && (gb[i + 2] == u) && (gb[i + 1] != x))
            return (i + 1);
    }
    if ((gb[0] == gb[4]) && (gb[4] == u) && (gb[8] != x))
        return 8;
    if ((gb[4] == gb[8]) && (gb[8] == u) && (gb[0] != x))
        return 0;
    if ((gb[0] == gb[8]) && (gb[8] == u) && (gb[4] != x))
        return 4;
    if ((gb[2] == gb[4]) && (gb[4] == u) && (gb[6] != x))
        return 6;
    if ((gb[4] == gb[6]) && (gb[6] == u) && (gb[2] != x))
        return 2;
    if ((gb[2] == gb[6]) && (gb[6] == u) && (gb[4] != x))
        return 4;
    return -2;
}

int main() {
    int ch;
    int size = 9;

    cout << "--------Tic Tac Toe-------\n";
    cout << "User 1 : Enter your choice ( X or O ) : \n";
    string u1;
    cin >> u1;
    string u2 = "";

    if (u1 == "X")
        u2 = "O";
    else if (u1 == "O")
        u2 = "X";
    else {
        cout << "Invalid Choice\n";
        exit(0);
    }

    cout << "User 1 : " << u1 << "\n";
    cout << "User 2 : " << u2 << "\n";

    int ms[] = {8, 3, 4, 1, 5, 9, 6, 7, 2};
    vector<string> gb(size);

    for (int i = 0; i < size; i++)
        gb[i] = to_string(i);

    do {
        cout << "1) Play \n2) Exit\n";
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch (ch) {
        case 1:
            printGameBoard(size, gb, ms, u1, u2);
            cout << "\nEnter the number you want to insert for " << u1 << " : ";
            int row;
            cin >> row;
            if (gb[row] != u1 && gb[row] != u2)
                gb[row] = u1;
            else {
                cout << "Invalid Move\n";
                break;
            }
            cout << "User : \n";
            printGameBoard(size, gb, ms, u1, u2);
            computerTurn(size, gb, u1, ms, u2);
        }
    } while (ch != 2);

    return 0;
}

