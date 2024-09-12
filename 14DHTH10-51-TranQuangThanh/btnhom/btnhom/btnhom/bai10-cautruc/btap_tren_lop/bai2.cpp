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
void terminateNewLine(char *a)
{
    char *newline = strchr(a, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
}
void input(struct staff *a)
{
    printf("Nhap ma nhan vien: ");
    fgets(a->code, sizeof a->code, stdin);
    terminateNewLine(a->code);
    printf("Nhap ten nhan vien: ");
    fgets(a->name, sizeof a->name, stdin);
    terminateNewLine(a->name);
    do
    {
        printf("Nhap so ngay cong: ");
        scanf("%d", &a->workday);
        if (a->workday < 0)
            printf("Gia tri khong hop le!\n");
    } while (a->workday < 0);
    do
    {
        printf("Nhap luong mot ngay cong: ");
        scanf("%f", &a->one_day_salary);
        if (a->one_day_salary < 0)
            printf("Gia tri khong hop le!\n");
    } while (a->one_day_salary < 0);
    printf("Nhap chuc vu: ");
    getchar();
    fgets(a->position, sizeof a->position, stdin);
    terminateNewLine(a->position);
}
void display(struct staff a)
{
    float sum = a.workday * a.one_day_salary;
    printf("\nTong luong: %.2f\n", sum);
    if (a.workday > 24)
    {
        sum += 50;
        printf("Thuong 50$\n");
    }
    else
        printf("Khong thuong\n");
    printf("Tien phu cap chuc vu: ");
    if (strcmp(a.position, "Giam Doc") == 0)
    {
        printf("100$\n");
        sum += 100;
    }
    else if (strcmp(a.position, "Pho Giam Doc") == 0)
    {
        printf("80$\n");
        sum += 80;
    }
    else if (strcmp(a.position, "Truong Phong") == 0)
    {
        printf("60$\n");
        sum += 60;
    }
    else if (strcmp(a.position, "Pho Phong") == 0)
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
    struct staff a;
    input(&a);
    display(a);
    return 0;
}