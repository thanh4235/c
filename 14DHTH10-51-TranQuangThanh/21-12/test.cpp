#include <stdio.h>
#include <string.h>
struct student
{
    char name[20];
    int quantity;
};
void input(struct student a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNHAP THONG TIN SINH VIEN THU %d!\n", i + 1);
        getchar();
        printf("Nhap ten: ");
        gets(a[i].name);
        printf("Nhap so luong: ");
        scanf("%d", &a[i].quantity);
    }
}
int check(struct student a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].name, "Non") == 0)
            dem++;
    }
    return dem;
}
int main()
{
    struct student a[20];
    int n;
    do
    {
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
        if (n < 0)
            printf("Gia tri khong hop le\n");
    } while (n < 0);
    input(a, n);
    printf("\nCo hay khong?? ");
    if (check(a, n) > 0)
        printf("Co");
    else
        printf("Khong");

    return 0;
}