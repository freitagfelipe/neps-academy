#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int signal(int x) {
    if (x < 0) {
        return -1;
    } else if (x > 0) {
        return 1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> arena;

    ll sum {};

    for (int i {}; i < n; ++i) {
        int x;

        cin >> x;

        sum += x;

        if (arena.size() == 0 || signal(x) == signal(arena.back())) {
            arena.push_back(x);

            continue;
        }

        while (arena.size() > 0 && signal(x) != signal(arena.back())) {
            if (abs(x) > abs(arena.back())) {
                x += arena.back();

                arena.pop_back();
            } else if(abs(x) == abs(arena.back())) {
                x = 0;

                arena.pop_back();

                break;
            } else {
                arena.back() += x;

                x = 0;

                break;
            }
        }

        if (abs(x) > 0) {
            arena.push_back(x);
        }
    }

    if (sum == 0) {
        cout << "Tie!\n";

        return 0;
    }

    if (arena.back() > 0) {
        cout << "Positives win!\n";
    } else {
        cout << "Negatives win!\n";
    }

    int c {};

    for (int x : arena) {
        if (c++ > 0) {
            cout << " ";
        }

        cout << x;
    }

    cout << '\n';

    return 0;
}