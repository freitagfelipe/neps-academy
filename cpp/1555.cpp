#include <iostream>

using namespace std;

int fast_exponentiation(int b, int e, int m) {
    if (e == 0) {
        return 1 % m; 
    }

    long long int answer {fast_exponentiation(b, e / 2, m)};

    answer = (answer * answer) % m;

    if (e % 2 == 0) {
        return answer;
    }

    return (answer * b) % m;
}

int main() {
    int a, b, m;

    cin >> a >> b >> m;

    cout << fast_exponentiation(a, b, m) << '\n';

    return 0;
}
