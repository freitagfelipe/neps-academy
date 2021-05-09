#include <iostream>

int main() {
    int A, B, C, W[3];

    std::cin >> A >> B >> C;

    (A < B && A < C) ? W[0] = 1 : (A < B || A < C) ? W[1] = 1 : W[2] = 1;
    (B < A && B < C) ? W[0] = 2 : (B < A || B < C) ? W[1] = 2 : W[2] = 2;
    (C < A && C < B) ? W[0] = 3 : (C < A || C < B) ? W[1] = 3 : W[2] = 3;

    for(int i = 0; i < 3; i++)
        std::cout << W[i] << std::endl;

    return 0;
}