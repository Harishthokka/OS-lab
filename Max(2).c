#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("Maximum = %d", max(x, y));
    return 0;
}
