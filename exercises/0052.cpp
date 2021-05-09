#include <iostream>

int main() {
    int N, X, A = 0, B = 0;

    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::cin >> X;

        if(X == 1) {
            if(A == 0)
                A = 1;
            else
                A = 0;
        } else {
            if(A == 1)
                A = 0;
            else
                A = 1;
            
            if(B == 0)
                B = 1;
            else
                B = 0;
        }
    }

    std::cout << A << "\n" << B << std::endl;

    return 0;
}