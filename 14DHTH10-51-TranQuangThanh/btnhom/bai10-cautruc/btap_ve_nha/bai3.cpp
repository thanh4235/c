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
void input(struct phone *first)
{
    printf("Nhap ma dien thoai: ");
    scanf("%s", first->code);
    printf("Nhap ten dien thoai: ");
    scanf("%s", first->name);
    printf("Nhap loai dien thoai: ");
    scanf("%s", first->sort);
    do
    {
        printf("Nhap gia: ");
        scanf("%f", &first->price);
        if (first->price <= 0)
            printf("Gia tri khong hop le!\n");
    } while (first->price <= 0);
    do
    {
        printf("Nhap so luong: ");
        scanf("%d", &first->quantity);
        if (first->quantity <= 0)
            printf("Gia tri khong hop le\n");
    } while (first->quantity <= 0);
}
void display(struct phone first)
{
    printf("\nMa dien thoai: %s\n", first.code);
    printf("Ten dien thoai: %s\n", first.name);
    printf("Loai dien thoai: %s\n", first.sort);
    printf("Gia: %f\n", first.price);
    printf("So luong: %d\n", first.quantity);
    if (strcmp(first.name, "Galaxy") == 0)
        printf("\nDien thoai cua hang Galaxy\n");
    else
        printf("\nDien thoai khong phai cua hang Galaxy\n");

    if (first.price <= 5000000)
        printf("\nThuoc phan khuc binh dan\n");
    if (first.price > 5000000 && first.price < 10000000)
        printf("\nThuoc phan khuc trung cap\n");
    if (first.price > 10000000)
        printf("\nThuoc phan khuc cao cap\n");
    if (first.quantity < 5)
        printf("\nNhap hang\n");
}
int main()
{
    struct phone first;
    input(&first);
    display(first);
    return 0;
}
