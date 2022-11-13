#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;

    cin >> n;

    set<int> s;

    int answer {};

    for (int i {}; i < n; ++i) {
        int aux;

        cin >> aux;

        auto [it, b] = s.insert(aux);

        if (b) {
            ++answer;
        }
    }

    cout << answer << '\n';

    return 0;
}