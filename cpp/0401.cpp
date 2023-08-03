#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int minv {0xf3f3f3};
    int arr[10];

    for (int i {}; i < 10; ++i) {
        cin >> arr[i];

        minv = min(minv, arr[i]);
    }

    cout << "Menor: " << minv << '\n';

    vector<int> occ;

    for (int i {}; i < 10; ++i) {
        if (arr[i] == minv) {
            occ.push_back(i);
        }
    }

    cout << "Ocorrencias: ";

    int c {};

    for (int idx : occ) {
        if (c++ > 0) {
            cout << " ";
        }

        cout << idx;
    }

    cout << '\n';

    for (int i {}; i < 10; ++i) {
        cout << (arr[i] == minv ? -1 : arr[i]) << " \n"[i + 1 == 10];
    }

    return 0;
}