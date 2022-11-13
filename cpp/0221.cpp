#include <iostream>

using namespace std;

int main() {
    int n, p;

    cin >> n >> p;

    int count = 0;

    for (int i = 0; i < n; ++i) {
        int f1, f2;

        cin >> f1 >> f2;

        if (f1 + f2 >= p)
            count++;
    }

    cout << count << endl;

    return 0;
}