#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> pis;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    unordered_map<string, int> last_time_saw, name_to_idx;
    vector<pis> v;

    for (int i {}; i < n; ++i) {
        string name;
        int time;

        cin >> name >> time;

        if (name_to_idx.count(name) == 0) {
            name_to_idx[name] = v.size();
            last_time_saw[name] = time;

            v.emplace_back(1, name);
            
            continue;
        }

        if (time - last_time_saw[name] >= k) {
            ++v[name_to_idx[name]].first;
            last_time_saw[name] = time;
        }
    }

    cout << "--Rank do Nepscord--\n";

    sort(v.begin(), v.end(), [](const pis &a, const pis &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }

        return a.first > b.first;
    });

    int bound {min(3, (int) v.size())};

    for (int i {}; i < bound; ++i) {
        cout << "#" << i + 1 << ". " << v[i].second << " - Nivel " << v[i].first * 25 / 100 + 1 << '\n';
    }

    for (int i {bound}; i < 3; ++i) {
        cout << "#" << i + 1 << ".\n";
    }

    return 0;
}
