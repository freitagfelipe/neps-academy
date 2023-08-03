#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solver(vector<vector<int>> &v, int i, int j) {
    int answer {};

    while (true) {
        v[i][j] = -1;
        ++answer;

        if (v[i][j + 1] == 1) {
            ++j;
        } else if (v[i][j - 1] == 1) {
            --j;
        } else if (v[i + 1][j] == 1) {
            ++i;
        } else if (v[i - 1][j] == 1) {
            --i;
        } else {
            ++answer;

            break;
        }
    }

    return answer;
}

int main() {
    int l, c;

    cin >> l >> c;

    vector<vector<int>> v(l + 2, vector<int>(c + 2, 0));

    int i_inicio, j_inicio;

    for (int i {1}; i <= l; ++i) {
        for (int j {1}; j <= c; ++j) {
            cin >> v[i][j];

            if (v[i][j] == 3) {
                i_inicio = i;
                j_inicio = j;
            }
        }
    }

    cout << solver(v, i_inicio, j_inicio) << '\n';

    return 0;
}