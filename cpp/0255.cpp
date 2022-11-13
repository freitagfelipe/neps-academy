#include <iostream>

using namespace std;

#define MAXN 100000

int v[MAXN + 1];

void binary_search(int x, int n) {
    int initial_index {-1}, end_index {};

    bool not_find_answer {true};

    while (not_find_answer) {
        int start {}, end {n - 1};

        ++initial_index;

        while (start <= end) {
            int mid {(start + end) / 2};

            int sum {v[initial_index] + v[mid]};

            if (x - sum == 0) {
                end_index = mid;

                not_find_answer = false;

                break;
            } else if (x - sum < 0) {
                end = mid - 1;
            } else if (x - sum > 0) {
                start = mid + 1;
            }
        }
    }

    cout << v[initial_index] << " " << v[end_index] << '\n';
}

int main() {
    int n, k;

    cin >> n;

    for (int i {}; i < n; ++i) {
        cin >> v[i];
    }

    cin >> k;

    binary_search(k, n);

    return 0;
}