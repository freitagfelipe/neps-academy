#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> LIS(vector<int> &v) {
    vector<int> lis;
    vector<int> answer;

    for (int i {}; i < v.size(); ++i) {
        vector<int>::iterator it {lower_bound(lis.begin(), lis.end(), v[i])};

        long int distance {it - lis.begin()};

        if (it == lis.end()) {
            lis.push_back(v[i]);
        } else {
            *it = v[i];
        }

        answer.push_back(distance + 1);
    }

    return answer;
}

int solver(vector<int> &v) {
    vector<int> lis{LIS(v)};

    reverse(v.begin(), v.end());

    vector<int> r_lis(LIS(v));

    reverse(r_lis.begin(), r_lis.end());

    int result {};

    for (int i {}; i < v.size(); ++i) {
        if (lis[i] == r_lis[i] && (lis[i] + r_lis[i]) % 2 == 0) {
            result = max(result, lis[i] + r_lis[i] - 1);
        }
    }

    return result;
}

int main() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    cout << solver(v) << '\n';

    return 0;
}