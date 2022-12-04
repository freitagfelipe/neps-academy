#include <iostream>

using namespace std;

#define MAXN 105

int l, c;
int ans_i, ans_j;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
char mat[MAXN][MAXN];

bool is_valid_cell(int i, int j) {
    if (i < 0 || i >= l || j < 0 || j >= c) {
        return false;
    } else if (mat[i][j] == '.') {
        return false;
    }

    return true;
}

void dfs(int ri, int rj) {
    ans_i = ri;
    ans_j = rj;

    mat[ri][rj] = '.';

    for (int i {}; i < 4; ++i) {
        int ci {ri + di[i]};
        int cj {rj + dj[i]};

        if (is_valid_cell(ci, cj)) {
            dfs(ci, cj);
        }
    }
}

int main() {
    int si, sj;

    cin >> l >> c;
    
    for (int i {}; i < l; ++i) {
        for (int j {}; j < c; ++j) {
            cin >> mat[i][j];

            if (mat[i][j] == 'o') {
                si = i;
                sj = j;
            }
        }
    }

    dfs(si, sj);

    cout << ans_i + 1 << " " << ans_j + 1 << '\n';

    return 0;
}
