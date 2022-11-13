#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIS(vector<int> &v) {
    vector<int> lis;

    for (int i {0}; i < v.size(); ++i) {
        vector<int>::iterator it {upper_bound(lis.begin(), lis.end(), v[i])};

        if (it == lis.end()) {
            lis.push_back(v[i]);
        } else {
            *it = v[i];
        }
    }

    return lis.size();
}

int main() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    cout << LIS(v) << '\n';

    return 0;
}