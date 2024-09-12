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
void terminateNewLine(char *a)
{
    char *newline = strchr(a, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
}
void input(struct invoice *a)
{
    printf("Nhap ma hoa don: ");
    fgets(a->invoiceCode, sizeof a->invoiceCode, stdin);
    terminateNewLine(a->invoiceCode);
    printf("Nhap ten khach hang: ");
    fgets(a->customerName, sizeof a->customerName, stdin);
    terminateNewLine(a->customerName);
    printf("Nhap ten san pham: ");
    fgets(a->productName, sizeof a->productName, stdin);
    terminateNewLine(a->productName);
    do
    {
        printf("Nhap gia: ");
        scanf("%f", &a->price);
        if (a->price <= 0)
            printf("Gia tri khong hop le!!\n");
    } while (a->price <= 0);
    do
    {
        printf("Nhap so luong: ");
        scanf("%d", &a->quantity);
        if (a->quantity <= 0)
            printf("Gia tri khong hop le!!\n");
    } while (a->quantity <= 0);
}
float discount(struct invoice a)
{
    float sum1 = a.price * a.quantity, sum2 = sum1;
    if (a.quantity > 50)
        sum1 = sum1 * (1 - 0.1);
    if (strcmp(a.productName, "chuot mitsumi") == 0)
        sum1 = sum1 * (1 - 0.05);
    return sum2 - sum1;
}
void display(struct invoice a)
{
    printf("\nMa hoa don: %s\n", a.invoiceCode);
    printf("Ten khach hang: %s\n", a.customerName);
    printf("Ten san pham: %s\n", a.productName);
    printf("Gia: %.2f\n", a.price);
    printf("So luong: %d\n", a.quantity);
    printf("\nTong tien: %.2f\n", a.price * a.quantity);
    printf("Giam gia: %2.f\n", discount(a));
    printf("So tien phai tra: %.2f\n", (a.price * a.quantity) - discount(a));
}
int main()
{
    invoice a;
    input(&a);
    display(a);
    return 0;
}