#include <iostream>

int main() {
    int N;

    std::cin >> N;

    int colors[N];

    for(int i = 0; i < N; i++)
        std::cin >> colors[i];

    for(int i = 0; i < N; i++) {
        int a1 = 0;

        for(int j = 0, y = i, x = i; j < N; j++, x++, y--) {
            if(y > -1)
                if(colors[y] == 0 && y > -1)
                    break;

            if(x < N)
                if(colors[x] == 0)
                    break;

            a1++;
        }

        if(a1 > 8)
            a1 = 9;
        
        std::cout << a1 << " ";
    }

    std::cout << '\n';

    return 0;
}