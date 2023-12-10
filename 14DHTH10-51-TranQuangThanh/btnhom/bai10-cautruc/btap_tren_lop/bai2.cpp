#include <stdio.h>
#include <string.h>
struct staff
{
    char code[100];
    char name[100];
    int workday;
    float one_day_salary;
    char position[100];
};
char *inputStringWithSpace(char *__restrict__ _Buf, int _MaxCount)
{
    while ((getchar()) != '\n')
        ;
    return fgets(_Buf, _MaxCount, stdin);
}
void input(struct staff *first)
{
    printf("Nhap ma nhan vien: ");
    scanf("%s", first->code);
    printf("Nhap ten nhan vien: ");
    scanf("%s", first->name);
    do
    {
        printf("Nhap so ngay cong: ");
        scanf("%d", &first->workday);
        if (first->workday < 0)
            printf("Gia tri khong hop le!\n");
    } while (first->workday < 0);
    do
    {
        printf("Nhap luong mot ngay cong: ");
        scanf("%f", &first->one_day_salary);
        if (first->one_day_salary < 0)
            printf("Gia tri khong hop le!\n");
    } while (first->one_day_salary < 0);
    printf("Nhap chuc vu: ");
    // scanf("%s", first->position);
    inputStringWithSpace(first->position, 100);
}
void display(struct staff first)
{
    float sum = first.workday * first.one_day_salary;
    printf("\nTong luong: %.2f\n", sum);
    if (first.workday > 24)
    {
        sum += 50;
        printf("Thuong 50$\n");
    }
    else
        printf("Khong thuong\n");
    printf("Tien phu cap chuc vu: ");
    if (strcmp(first.position, "Giam Doc") == 0)
    {
        printf("100$\n");
        sum += 100;
    }
    else if (strcmp(first.position, "PhoGiamDoc") == 0)
    {
        printf("80$\n");
        sum += 80;
    }
    else if (strcmp(first.position, "TruongPhong") == 0)
    {
        printf("60$\n");
        sum += 60;
    }
    else if (strcmp(first.position, "PhoPhong") == 0)
    {
        printf("40$\n");
        sum += 40;
    }
    else
        printf("0$\n");
    printf("Luong thuc lanh: %.2f", sum);
}
int main()
{
    struct staff first;
    input(&first);
    display(first);
    // inputStringWithSpace();
    return 0;
}