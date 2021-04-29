#include <iostream>

int main() {
    int A, B, C, H, L;
    char answer = 'N';

    std::cin >> A >> B >> C >> H >> L;

    if((A <= H && B <= L) || (A <= L && B <= H) || (A <= H && C <= L) || (A <= L && C <= H) || (B <= H && C <= L) || (B <= L && C <= H))
        answer = 'S';

    std::cout << answer << std::endl;

    return 0;
}