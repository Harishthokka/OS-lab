#include <stdio.h>

int power(int base, int exp) {
    int result = 1;
    for (int i = 1; i <= exp; i++)
        result *= base;
    return result;
}

int main() {
    int b, e;
    scanf("%d %d", &b, &e);
    printf("Power = %d", power(b, e));
    return 0;
}
