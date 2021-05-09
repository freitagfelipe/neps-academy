#include <iostream>

int main() {
    int time[6];

    for(int i = 0; i < 6; i++)
        std::cin >> time[i];

    std::cout << (time[3] * 86400 + time[4] * 3600 + time[5] * 60) - (time[0] * 86400 + time[1] * 3600 + time[2] * 60) << std::endl;

    return 0;
}