#include <stdio.h>

int main() {
    int number1, number2;

    scanf("%d %d", &number1, &number2);

    printf("%d", (number1 * 4 + number2 * 6) / 10);

    return 0;
}