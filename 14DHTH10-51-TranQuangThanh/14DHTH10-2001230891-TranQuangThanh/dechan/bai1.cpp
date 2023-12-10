#include <stdio.h>
#include <conio.h>
int main()
{
    int giolam, luonggio, luong;

    do
    {
        printf("Nhap so gio lam: ");
        scanf("%d", &giolam);
        if (giolam < 5)
            printf("So gio lam khong duoc nho hon 5");
    } while (giolam < 5);

    do
    {
        printf("Nhap luong gio: ");
        scanf("%d", &luonggio);
        if (luonggio < 0)
            printf("Luong gio phai la so duong");
    } while (luonggio < 0);

    if (giolam > 40)
        luong = 40 * luonggio + (giolam - 40) * luonggio * 1.5;
    else if (giolam < 20)
        luong = giolam * luonggio * (1 - 0.2);
    else
        luong = giolam * luonggio;
    printf("Lương: %d", luong);

    getch();
    return 0;
}