#include <bits/stdc++.h>

using namespace std;

int circular_kadane(vector<int> &v) {
    int all {v[0]};
    int ans {v[0]}, sum {v[0]};
    int inverse_ans {v[0] * -1}, inverse_sum {v[0] * -1};

    for (int i {1}; i < (int) v.size(); ++i) {
        inverse_sum = max(v[i] * -1, inverse_sum + v[i] * -1);
        inverse_ans = max(inverse_ans, inverse_sum);

        sum = max(v[i], sum + v[i]);
        ans = max(ans, sum);

        all += v[i];
    }

    return max(ans, all + inverse_ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int &x : v) {
        cin >> x;
    }

    cout << circular_kadane(v) << '\n';

    return 0;
}