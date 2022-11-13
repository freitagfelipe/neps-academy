#include <iostream>
#include <set>

using namespace std;

int solver(set<int> &n, set<int> &m) {
    set<int> fn, fm;

    for (int num : n) {
        if (m.find(num) == m.end()) {
            fn.insert(num);
        }
    }

    for (int num : m) {
        if (n.find(num) == n.end()) {
            fm.insert(num);
        }
    }

    return min(fn.size(), fm.size());
}

int main() {
    int n, m;

    cin >> n >> m;

    set<int> ns, ms;

    for (int i {}; i < n; ++i) {
        int aux;

        cin >> aux;

        ns.insert(aux);
    }

    for (int i {}; i < m; ++i) {
        int aux;

        cin >> aux;
        
        ms.insert(aux);
    }

    cout << solver(ns, ms) << '\n';

    return 0;
}