#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

#define MAXN 40

int n;

vector<string> topological_sort(unordered_map<string, vector<string>> &g) {
    unordered_map<string, int> in_degree;

    for (auto [k, v] : g) {
        in_degree[k];

        for (auto s : v) {
            ++in_degree[s];
        }
    }

    queue<string> q;

    for (auto [k, v] : in_degree) {
        if (v == 0) {
            q.push(k);
        }
    }

    cout << "s: " << q.size() << '\n';

    vector<string> ans;

    while (!q.empty()) {
        string curr {q.front()};

        q.pop();

        ans.push_back(curr);

        for (string v : g[curr]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (ans.size() != n) {
        return {};
    }

    return ans;
}

int main() {
    int test {1};

    while (cin >> n  && n != 0) {
        cout << "Teste " << test++ << '\n';

        unordered_map<string, vector<string>> g;

        for (int i {}; i < n; ++i) {
            string s;

            cin >> s;

            g[s] = {};
        }

        for (int i {}; i < n; ++i) {
            string s;
            int q;

            cin >> s >> q;

            for (int j {}; j < q; ++j) {
                string aux;

                cin >> aux;

                g[aux].push_back(s);
            }
        }

        vector<string> ans {topological_sort(g)};

        if (ans.size() == 0) {
            cout << "impossivel";
        } else {
            int count {};

            for (string s : ans) {
                if (count++ > 0) {
                    cout << " ";
                }

                cout << s;
            }
        }


        cout << "\n\n";
    }

    return 0;
}
