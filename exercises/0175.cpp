#include <iostream>

bool is_prime(int X);

int main() {
	int X;

	std::cin >> X;

	if(is_prime(X))
		std::cout << "S" << "\n";
	else
		std::cout << "N" << "\n";
}

bool is_prime(int X) {
	if(X == 1)
		return false;

	for(int i = 2; i < X; i++) {
        if(X % i == 0)
            return false;
	}

    return true;
}