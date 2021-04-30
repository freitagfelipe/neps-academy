#include <iostream>

int main() {
    int M[3][3];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            std::cin >> M[i][j];

    for(int i = 0; i < 3; i++) {
        int answer = 0;

        for(int j = 0; j < 3; j++)
            answer += M[j][i];
        
        std::cout << "Coluna " << i << ": " << answer << std::endl;
    }

    return 0;
}