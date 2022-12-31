#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN int(1e5 + 10)

int arr[MAXN];

int gdc(int a, int b) {
    if (a == 0) {
        return b;
    }

    return gdc(b % a, a);
}

int solver(int n) {
    int result {arr[0]};

    for (int i {1}; i < n; ++i) {
        result = gdc(arr[i], result);

        if (result == 1) {
            return 1;
        }
    }

    return result;
}

int main() {
    int n;

    cin >> n;

    for (int i {}; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << solver(n) << '\n';

    return 0;
}
