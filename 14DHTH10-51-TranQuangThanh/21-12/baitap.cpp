#include <stdio.h>
#include <string.h>

struct student
{
    char name[100];
    int age;
    float score;
};
void input(struct student *a)
{
    printf("Nhap ten: ");
    scanf("\n");
    gets(a->name);
    do
    {
        printf("Nhap tuoi: ");
        scanf("%d", &a->age);
        if (a->age < 0)
            printf("Gia tri khong hop le\n");
    } while (a->age < 0);
    do
    {
        printf("Nhap diem: ");
        scanf("%f", &a->score);
        if (a->score < 0)
            printf("Gia tri khong hop le\n");
    } while (a->score < 0);
}
void comparison(struct student a, struct student b)
{
    printf("\nKet qua so sanh:\n");
    // So sanh ten
    if (strcmp(a.name, b.name) == 0)
        printf("Ten hai ban trung nhau\n");
    else
        printf("Ten hai ban khong trung nhau\n");
    // So sanh tuoi
    printf("Tuoi ban thu nhat ");
    if (a.age > b.age)
        printf("lon hon");
    else if (a.age == b.age)
        printf("bang");
    else
        printf("nho hon");
    printf(" ban thu hai\n");
    // So sanh diem
    printf("Diem ban thu nhat ");
    if (a.score > b.score)
        printf("lon hon");
    else if (a.score == b.score)
        printf("bang");
    else
        printf("nho hon");
    printf(" ban thu hai\n");
}
int main()
{
    struct student a, b;
    printf("Nhap thong tin sinh vien thu nhat!!\n");
    input(&a);
    printf("\nNhap thong tin sinh vien thu hai!!\n");
    input(&b);
    comparison(a, b);
    return 0;
}