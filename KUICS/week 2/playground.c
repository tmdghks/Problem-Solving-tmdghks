#include <stdio.h>

int main() {
    int T;
    int a, b, c;
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case #%d: ", i);
        if (!(a < (b + c) && b - c < a && c - b < a)) {
            printf("invalid!\n");
        } else {
            if (a == b && b == c) {
                printf("equilateral\n");
            } else if (a == b || b == c || c == a) {
                printf("isosceles\n");
            } else {
                printf("scalene\n");
            }
        }
    }
}