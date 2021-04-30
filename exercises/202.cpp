#include <iostream>

int main() {
    int M[3][3], biggest = 0;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            std::cin >> M[i][j];

            if(M[i][j] > biggest || (i == 0 && j == 0))
                biggest = M[i][j];
        }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(M[i][j] == biggest)
                M[i][j] = -1;
            
            std::cout << M[i][j] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}