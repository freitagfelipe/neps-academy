#include<iostream>
#include<vector>

using namespace std;

void solver(vector<vector<char>> &v, int i, int j) {
    v.at(i).at(j) = 'o';

    if (i + 1 >= v.size()) {
        return;
    }

    if (v.at(i + 1).at(j) == '#') {
        if (j > 0 && v.at(i).at(j - 1) != 'o') {
            solver(v, i, j - 1);
        }

        if (j < v.at(0).size() - 1 && v.at(i).at(j + 1) != 'o') {
            solver(v, i, j + 1);
        }
    } else {
        solver(v, i + 1, j);
    }
}

int main() {
    int lines, columns, posX;

    cin >> lines >> columns;

    vector<vector<char>> v(lines, vector<char>());

    cin.ignore();

    for (int i {0}; i < lines; ++i) {
        for (int j {0}; j < columns; ++j) {
            char ch;

            cin >> ch;

            v.at(i).push_back(ch);

            if (ch == 'o') {
                posX = j;
            }
        }
    }

    solver(v, 0, posX);

    cout << "\n\n";

    for (const vector<char> &i : v) {
        for (const char &c : i) {
            cout << c;
        }

        cout << endl;
    }

    return 0;
}