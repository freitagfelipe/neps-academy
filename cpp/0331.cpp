#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 50010

int n;
int in_degree[MAXN];
vector<int> g[MAXN];

vector<int> topological_sort() {
    for (int i {}; i < n; ++i) {
        for (int v : g[i]) {
            ++in_degree[v];
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i {}; i < n; ++i) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> ans;

    while (!pq.empty()) {
        int curr {pq.top()};

        pq.pop();

        ans.push_back(curr);

        for (int v : g[curr]) {
            if (--in_degree[v] == 0) {
                pq.push(v);
            }
        }
    }

    if (ans.size() != n) {
        return {};
    }

    return ans;
}

int main() {
    int m;

    cin >> n >> m;

    for (int i {}; i < m; ++i) {
        int a, b;

        cin >> a >> b;

        g[a].push_back(b);
    }
    

    vector<int> ans {topological_sort()};

    if (ans.size() == 0) {
        cout << "*\n";
    } else {
        for (int x : ans) {
            cout << x << '\n';
        }
    }

    return 0;
}
