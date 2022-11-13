#include <iostream>

using namespace std;

#define MAXN 101

int answer;
bool choosed[MAXN];

void solver(int r, int k, int current) {
    if (r == 0 && k == 0) {
        ++answer;

        return;
    } else if (r < 0 || k == 0) {
        return;
    }

    for (int i {current}; i <= r; ++i) {
        if (!choosed[i]) {
            choosed[i] = true;

            solver(r - i, k - 1, i + 1);

            choosed[i] = false;
        }
    }
}

int main() {
    int r, k;

    cin >> r >> k;

    solver(r, k, 1);
    
    cout << answer << '\n';

    return 0;
}