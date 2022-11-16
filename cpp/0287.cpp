#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int start, int end) {
    vector<int> result;

    int p1 {start}, mid {(start + end) / 2}, p2 {mid + 1};

    while (p1 <= mid && p2 <= end) {
        if (v[p1] >= v[p2]) {
            result.push_back(v[p1++]);
        } else {
            result.push_back(v[p2++]);
        }
    }

    while (p1 <= mid) {
        result.push_back(v[p1++]);
    }

    while (p2 <= end) {
        result.push_back(v[p2++]);
    }

    copy(result.begin(), result.end(), v.begin() + start);
}

void merge_sort(vector<int> &v, int start, int end) {
    if (end > start) {
        int mid {(start + end) / 2};

        merge_sort(v, start, mid);
        merge_sort(v, mid + 1, end);

        merge(v, start, end);
    }
}

int main() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    merge_sort(v, 0, n - 1);

    int count {};

    for (int num : v) {
        if (count++ > 0) {
            cout << " ";
        }

        cout << num;
    }

    cout << '\n';

    return 0;
}
