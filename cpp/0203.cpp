#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q;

    for (int i {1}; i <= 16; ++i) {
        q.push(i);
    }

    int k, l;

    cin >> k >> l;

    while (true) {
        int p1, p2;

        p1 = q.front();

        q.pop();

        p2 = q.front();

        q.pop();

        if ((p1 == k || p1 == l) && (p2 == k || p2 == l)) {
            break;
        }

        if (p1 == k || p1 == l) {
            q.push(p1);
        } else {
            q.push(p2);
        }
    }

    if (q.size() == 0) {
        cout << "final\n";
    } else if (1 <= q.size() && q.size() < 3) {
        cout << "semifinal\n";
    } else if (3 <= q.size() && q.size() < 7) {
        cout << "quartas\n";
    } else {
        cout << "oitavas\n";
    }

    return 0;
}