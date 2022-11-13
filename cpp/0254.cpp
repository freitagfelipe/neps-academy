#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int c, s;

    cin >> c >> s;

    vector<pair<int, int>> v;

    for (int i {}; i < s; ++i) {
        int start, end;    

        cin >> start >> end;

        v.push_back({start, end});
    }

    sort(v.begin(), v.end());

    cout << v[0].first << " ";

    int highest {v[0].second};

    for (int i {1}; i < s; ++i) {
        if (highest == v[i].second || (v[i].first <= highest && v[i].second > highest)) {
            highest = v[i].second;
        } else if (highest < v[i].first) {
            cout << highest << '\n' << v[i].first << " ";

            highest = v[i].second;
        }
    }

    cout << highest << '\n';

    return 0;
}