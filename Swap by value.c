#include <stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("After swap: a=%d b=%d\n", a, b);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    swap(x, y);
    printf("Original: x=%d y=%d", x, y);
    return 0;
}
