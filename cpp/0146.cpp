#include <iostream>

int main() {
    int X, Y;
    std::string answer;

    std::cin >> X >> Y;

    if(X == 0 || Y == 0)
        answer = "eixos";
    else {
        if(X > 0) {
            if(Y > 0)
                answer = "Q1";
            else
                answer = "Q4";
        } else {
            if(Y > 0)
                answer = "Q2";
            else
                answer = "Q3";
        }
    }

    std::cout << answer << std::endl;

    return 0;
}