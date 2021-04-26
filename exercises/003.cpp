#include <iostream>

long long mdc(long long n1, long long n2);

int main() {
    long long N, M, X;

    std::cin >> N >> M;

    for(long long int i = M; i > 0; i--)
        if(mdc(N, i) == 1) {
            X = i;
            break;
        }

    std::cout << X << std::endl;

    return 0;
}

long long mdc(long long n1, long long n2) {
    if(n1 < n2)
        std::swap(n1, n2);

    if(n2 == 0) 
        return n1;

    return mdc(n2, n1 % n2);
}