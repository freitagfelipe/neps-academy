#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<pii> v(12);

    for (int i {}; i < 12; ++i) {
        v[i].second = i + 1;
    }

    for (int i {}; i < n; ++i) {
        int x;
        
        cin >> x;

        ++v[x - 1].first;
    }

    sort(v.begin(), v.end(), [](const pii &a, const pii &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }

        return a.first > b.first;
    });

    for (int i {}; i < 11; ++i) {
        cout << v[i].second;

        if (v[i + 1].first == v[i].first) {
            cout << " ";
        } else {
            cout << '\n';

            break;
        }
    }

    return 0;
}