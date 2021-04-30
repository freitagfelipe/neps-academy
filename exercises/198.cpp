#include <iostream>

int main() {
    int M[3][3], column[3] = {0}, line[3] = {0}, mainDiagonal = 0, secondaryDiagonal = 0;
    std::string answer = "SIM";

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            std::cin >> M[i][j];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            column[i] += M[j][i];
            line[i] += M[i][j];
        }

        mainDiagonal += M[i][i];
        secondaryDiagonal += M[2 - i][i];
    }

    if(mainDiagonal != secondaryDiagonal) {
        answer = "NAO";
    } else {
        for(int i = 0; i < 3; i++) {
            if(line[i] != column[i] || line[i] != mainDiagonal || line[i] != secondaryDiagonal || column[i] != mainDiagonal || column[i] != secondaryDiagonal) {
                answer = "NAO";
                break;
            }
        }
    }

    std::cout << answer << std::endl;

    return 0;
}