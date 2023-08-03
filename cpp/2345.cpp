#include <bits/stdc++.h>

using namespace std;

void fill_quilt(vector<vector<char>> &mat, int row, int column, const vector<vector<char>> &quilt) {
    int ix {};

    for (int i {row}; i < (int) min(mat.size(), row + quilt.size()); ++i, ++ix) {
        int jx {};

        for (int j {column}; j < (int) min(mat[0].size(), column + quilt[0].size()); ++j, ++jx) {
            mat.at(i).at(j) = quilt.at(ix).at(jx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;

    cin >> n >> m >> q;

    vector<vector<char>> mat(n, vector<char>(m, '.'));
    vector<vector<vector<char>>> quilts;

    while (q--) {
        int qn, qm;

        cin >> qn >> qm;

        vector<vector<char>> quilt(qn, vector<char>(qm));

        for (vector<char> &row : quilt) {
            for (char &column : row) {
                cin >> column;
            }
        }

        quilts.push_back(quilt);
    }

    int k;

    cin >> k;

    while (k--) {
        int idx, row, column;

        cin >> row >> column >> idx;

        fill_quilt(mat, row, column, quilts.at(idx - 1));
    }

    for (vector<char> &row : mat) {
        for (char &column : row) {
            cout << column;
        }

        cout << '\n';
    }

    return 0;
}