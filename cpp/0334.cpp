#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int v[MAXN];

int main() {
    int n;

    cin >> n;

    int ans {n}, sum {};

    for(int i {}; i < n; i++) {
        cin >> v[i];

        sum += v[i];
    }

    sort(v, v + n, greater<int>());

    for(int i {}; i < n; i++) {
        if(v[i] >= sum - v[i]){
            ans--;

            sum -= v[i];
        } else {
            break;
        }
    }

    cout << (ans < 3 ? 0 : ans) << endl;

    return 0;
}