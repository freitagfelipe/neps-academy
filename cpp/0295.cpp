#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e7) + 10

int n;
int lpf[MAXN];
vector<int> pr;

int main() {
    cin >> n;

    for (int i {2}; i <= n; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            pr.push_back(i);
        }

        for (int j {}; i * pr[j] <= n; ++j) {
            lpf[i * pr[j]] = pr[j];

            if (lpf[i] == pr[j]) {
                break;
            }
        }
    }

    int count {};

    for (int num : pr) {
        if (count++ > 0) {
            cout << " ";
        }

        cout << num;
    }

    cout << '\n';

    return 0;
}
