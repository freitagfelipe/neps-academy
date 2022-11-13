#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<char> q;

    for (int i {}; i <= 15; ++i) {
        q.push('A' + i);
    }

    for (int i {}; i < 15; ++i) {
        int a, b;

        cin >> a >> b;

        if (a > b) {
            q.push(q.front());

            q.pop();
            q.pop();
        } else {
            q.pop();

            q.push(q.front());

            q.pop();
        }
    }

    cout << q.front() << '\n';

    return 0;
}