#include <stdio.h>
#include <string.h>
struct invoice
{
    char invoiceCode[100];
    char customerName[100];
    char productName[100];
    float price;
    int quantity;
};
void input(struct invoice *first)
{
    printf("Nhap ma hoa don: ");
    scanf("%s", first->invoiceCode);
    printf("Nhap ten khach hang: ");
    scanf("%s", first->customerName);
    printf("Nhap ten san pham: ");
    scanf("%s", first->productName);
    do
    {
        printf("Nhap gia: ");
        scanf("%f", &first->price);
        if (first->price <= 0)
            printf("Gia tri khong hop le!!\n");
    } while (first->price <= 0);
    do
    {
        printf("Nhap so luong: ");
        scanf("%d", &first->quantity);
        if (first->quantity <= 0)
            printf("Gia tri khong hop le!!\n");
    } while (first->quantity <= 0);
}
float discount(struct invoice first)
{
    float sum1 = first.price * first.quantity, sum2 = sum1;
    if (first.quantity > 50)
        sum1 = sum1 * (1 - 0.1);
    if (strcmp(first.productName, "mitsumi") == 0)
        sum1 = sum1 * (1 - 0.05);
    return sum2 - sum1;
}
void display(struct invoice first)
{
    printf("\nMa hoa don: %s\n", first.invoiceCode);
    printf("Ten khach hang: %s\n", first.customerName);
    printf("Ten san pham: %s\n", first.productName);
    printf("Gia: %.2f\n", first.price);
    printf("So luong: %d\n", first.quantity);
    printf("\nTong tien: %.2f\n", first.price * first.quantity);
    printf("Giam gia: %2.f\n", discount(first));
}
int main()
{
    invoice first;
    input(&first);
    display(first);
    return 0;
}