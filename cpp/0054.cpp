#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;

    cin >> n;

    unordered_set<int> s;

    int answer {};

    for (int i {}; i < n; ++i) {
        int aux;

        cin >> aux;

        auto [it, b] = s.insert(aux);

        if (b) {
            answer += 2;
        } else {
            s.erase(it);
        }
    }

    cout << answer << '\n';

    return 0;
}