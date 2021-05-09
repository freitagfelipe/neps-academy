#include <iostream>

int main() {
    int M, ages[3];

    std::cin >> M >> ages[0] >> ages[1];

    ages[2] = M - (ages[0] + ages[1]);

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(ages[i] > ages[j])
                std::swap(ages[i], ages[j]);

    std::cout << ages[0] << std::endl;

    return 0;
}