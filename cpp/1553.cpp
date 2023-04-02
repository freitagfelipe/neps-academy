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

int get_modular_inverse(int a, int m) {
	return fast_exponentiation(a, m - 2, m);
}

int main() {
    int n, m;

    cin >> n >> m;

    int ans {get_modular_inverse(n, m)};

    cout << (ans == 0 ? -1 : ans) << '\n';

    return 0;
}
