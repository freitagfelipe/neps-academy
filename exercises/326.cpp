#include <iostream>

int vector_sum(int N, int numbers[]) {
    int answer = 0;

	for(int i = 0; i < N; i++)
        answer += numbers[i];

    return answer;
}

int main() {
	int N;
	
	std::cin >> N;

    int numbers[N];
	
	for(int i = 0; i < N; i++)
		std::cin >> numbers[i];

	std::cout << vector_sum(N, numbers) << std::endl;
}