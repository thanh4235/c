#include<stdio.h>
int main() {
    int a, b, c;
    printf("Nhập vào 3 số nguyên: ");
    scanf("%d %d %d", &a, &b, &c);
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    int min = a;
    if (b < min) {
        min = b;
    }
     if (c < min) {
        min = c;
     }
     printf("Số lớn nhất là: %d\n", max);
     printf("Số nhỏ nhất là: %d\n", min);
     return 0; 
}