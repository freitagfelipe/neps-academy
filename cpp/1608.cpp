#include <iostream>

using namespace std;

int main() {
    long long int ax, ay, bx, by;

    cin >> ax >> ay >> bx >> by;

    cout << ax * bx + ay * by << " " << ax * by - ay * bx << '\n';

    return 0;
}
