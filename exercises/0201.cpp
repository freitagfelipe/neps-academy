#include <iostream>

int main() {
    int M[3][3], mainDiagonal = 0, secondaryDiagonal = 0;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            std::cin >> M[i][j];

    for(int i = 0; i < 3; i++) {
        mainDiagonal += M[i][i];
        secondaryDiagonal += M[2 - i][i];
    }

    std::cout << "Diagonal principal: " << mainDiagonal << "\nDiagonal secundaria: " << secondaryDiagonal << std::endl;

    return 0;
}