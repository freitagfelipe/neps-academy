#include <iostream>
#include <vector>

using namespace std;

int get_parent(int node) {
    return node / 2;
}

int check_binary_heap(vector<int> &v) {
    vector<int> res (v.size(), -2);

    for (int i {int(v.size() - 1)}; i > 1; --i) {
        int parent {get_parent(i)};

        if (v[parent] == v[i]) {
            continue;
        }

        int curr_base {v[parent] > v[i] ? 1 : -1};

        if (res[i] != -2 && res[i] != curr_base)  {
            return 0;
        }
        
        if (res[parent] == -2) {
            res[parent] = curr_base;
        } else if (res[parent] != curr_base || (res[i] != -2 && res[i] != res[parent])) {
            return 0;
        }
    }

    if (res[1] == -2) {
        return -1;
    }

    return res[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    for (int i {}; i < q; ++i) {
        vector<int> v(n + 1);

        for (int j {1}; j <= n; ++j) {
            cin >> v[j];
        }

        cout << check_binary_heap(v) << endl;
    }

    return 0;
}