#include <iostream>
#include <climits>

using namespace std;

#define MAXN 50000

int v[MAXN];

int main() {
    int n;

    cin >> n;

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    int answer {v[0]};
    int best {v[0]};

    for (int i {1}; i < n; ++i) {
        best = max(v[i], v[i] + best);
        answer = max(answer, best);
    }

    cout << answer << '\n';

    return 0;
}
