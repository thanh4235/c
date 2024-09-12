#include <stdio.h>
#include <string.h>
struct phone
{
    char code[10];
    char name[20];
    char sort[20];
    float price;
    int quantity;
};
void terminateNewLine(char *a)
{
    char *newline = strchr(a, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
}
void input(struct phone *a)
{
    printf("Nhap ma dien thoai: ");
    fgets(a->code, sizeof a->code, stdin);
    terminateNewLine(a->code);
    printf("Nhap ten dien thoai: ");
    fgets(a->name, sizeof a->name, stdin);
    terminateNewLine(a->name);
    printf("Nhap loai dien thoai: ");
    fgets(a->sort, sizeof a->sort, stdin);
    terminateNewLine(a->sort);
    do
    {
        printf("Nhap gia: ");
        scanf("%f", &a->price);
        if (a->price <= 0)
            printf("Gia tri khong hop le!\n");
    } while (a->price <= 0);
    do
    {
        printf("Nhap so luong: ");
        scanf("%d", &a->quantity);
        if (a->quantity <= 0)
            printf("Gia tri khong hop le\n");
    } while (a->quantity <= 0);
}
void display(struct phone a)
{
    printf("\nMa dien thoai: %s\n", a.code);
    printf("Ten dien thoai: %s\n", a.name);
    printf("Loai dien thoai: %s\n", a.sort);
    printf("Gia: %f\n", a.price);
    printf("So luong: %d\n", a.quantity);
    if (strcmp(a.name, "Galaxy") == 0)
        printf("\nDien thoai cua hang Galaxy\n");
    else
        printf("\nDien thoai khong phai cua hang Galaxy\n");

    if (a.price > 10000000)
        printf("\nThuoc phan khuc cao cap\n");
    else if (a.price > 5000000)
        printf("\nThuoc phan khuc trung cap\n");
    else
        printf("\nThuoc phan khuc binh dan\n");
    if (a.quantity < 5)
        printf("\nCan nhap hang\n");
}
int main()
{
    struct phone a;
    input(&a);
    display(a);
    return 0;
}
