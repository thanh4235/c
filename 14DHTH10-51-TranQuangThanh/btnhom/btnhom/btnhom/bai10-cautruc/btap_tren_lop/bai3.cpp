#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{
    char code[100];
    char name[100];
    float math;
    float physics;
    float chemistry;
};
void input(struct student *a)
{
    printf("Nhap nam sinh: ");
    getchar();
    gets(a->code);
    printf("Nhap ten sinh vien: ");
    getchar();
    gets(a->name);
    do
    {
        printf("Nhap diem toan: ");
        scanf("%f", &a->math);
        if (a->math < 0 || a->math > 10)
            printf("Gia tri khong hop le!\n");
    } while (a->math < 0 || a->math > 10);
    do
    {
        printf("Nhap diem ly: ");
        scanf("%f", &a->physics);
        if (a->physics < 0 || a->physics > 10)
            printf("Gia tri khong hop le!\n");
    } while (a->physics < 0 || a->physics > 10);
    do
    {
        printf("Nhap diem hoa: ");
        scanf("%f", &a->chemistry);
        if (a->chemistry < 0 || a->chemistry > 10)
            printf("Gia tri khong hop le!\n");
    } while (a->chemistry < 0 || a->chemistry > 10);
}
float average(struct student a)
{
    return (a.math + a.physics + a.chemistry) / 3;
}
struct student student_info(FILE *file)
{
    struct student a;
    fscanf(file, "%d\n", &a.code);
    fgets(a.name, sizeof(a.name), file);
    fscanf(file, "%f\n%f\n%f", &a.math, &a.physics, &a.chemistry);
    return a;
}

char *classification(struct student a)
{
    float dtb = average(a);
    if (dtb >= 8)
        return "Gioi";
    else if (dtb >= 6.5)
        return "Kha";
    else if (dtb >= 5)
        return "Trung binh";
    else
        return "Kem";
}
void display(struct student a)
{
    printf("\nNam sinh: %s\n", a.code);
    printf("Ten sinh vien: %s\n", a.name);
    printf("Diem toan: %.2f\n", a.math);
    printf("Diem ly: %.2f\n", a.physics);
    printf("Diem hoa: %.2f\n", a.chemistry);
    printf("Diem trung binh: %.2f\n", average(a));
    printf("Phan loai: %s\n", classification(a));
}
int main()
{
    struct student a;
    int n;
    printf("CHON 1 TRONG 2 PHUONG AN SAU:\n");
    printf("Nhap so 1: Doc file txt co san trong may\n");
    printf("Nhap so 2: Tu cung cap thong tin\n");
    while (n < 1 || n > 2)
    {
        printf("Vui long nhap so 1 hoac 2 de chon: ");
        scanf("%d", &n);
    }
    if (n == 1)
    {
        FILE *file;
        file = fopen("bai3.txt", "r");
        char scan[100];
        if (file == NULL)
        {
            printf("Khong the mo file!\n");
            return 0;
        }
        else
        {
            fgets(scan, sizeof scan, file);
            strcpy(a.code, scan);
            fgets(scan, sizeof scan, file);
            strcpy(a.name, scan);
            fgets(scan, sizeof scan, file);
            a.math = atoi(scan);
            fgets(scan, sizeof scan, file);
            a.physics = atoi(scan);
            fgets(scan, sizeof scan, file);
            a.chemistry = atoi(scan);
        }
        fclose(file);
    }
    else
        input(&a);
    display(a);
    return 0;
}