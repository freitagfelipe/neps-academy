#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (vector<int> &v : mat) {
        for (int &x : v) {
            cin >> x;
        }
    }

    vector<int> rows_s(n), columns_s(n);

    for (int i {}; i < n; ++i){
        for (int j {}; j < n; ++j) {
            rows_s[i] += mat[i][j];
            columns_s[i] += mat[j][i];
        }
    }

    int ans {};

    for (int i {}; i < n; ++i) {
        for (int j {}; j < n; ++j) {
            ans = max(ans, rows_s[i] + columns_s[j] - 2 * mat[i][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}