#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct taxi
{
    char code[20];
    char name[100];
    char location[150];
    float distance;
    int seat;
};
void terminateNewLine(char *a)
{
    char *newline = strchr(a, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
}
void input(struct taxi *a)
{
    printf("\nNHAP THONG TIN TAXI!!\n");
    printf("Nhap ma so: ");
    fgets(a->code, sizeof a->code, stdin);
    terminateNewLine(a->code);
    printf("Nhap ten tai xe: ");
    fgets(a->name, sizeof a->name, stdin);
    terminateNewLine(a->name);
    printf("Nhap dia chi don khach: ");
    fgets(a->location, sizeof a->location, stdin);
    terminateNewLine(a->location);
    do
    {
        printf("Nhap so km da chay: ");
        scanf("%f", &a->distance);
        if (a->distance < 0)
            printf("Gia tri khong hop le\n");
    } while (a->distance < 0);
    do
    {
        printf("Nhap so cho ngoi cua xe taxi: ");
        scanf("%d", &a->seat);
        if (a->seat < 0)
            printf("Gia tri khong hop le\n");
    } while (a->seat < 0);
}
void display(struct taxi a)
{
    printf("\nTHONG TIN TAXI:\n");
    printf("Ma so: %s\n", a.code);
    printf("Ten tai xe: %s\n", a.name);
    printf("Dia chi don khach: %s\n", a.location);
    printf("So km da chay: %.2f\n", a.distance);
    printf("So cho ngoi cua xe taxi: %d\n", a.seat);
}
void checkCode(struct taxi a, struct taxi b)
{
    printf("\nTai xe %s co chay taxi dang luu khong? ", b.name);
    if (strcmp(a.code, b.code) == 0)
        printf("CO\n");
    else
        printf("KHONG\n");
}
void checkLocation(struct taxi a, struct taxi b)
{
    printf("\nTai xe ");
    if (strcmp(b.location, "quan Tan Phu") == 0)
        printf("CO");
    else
        printf("KHONG CO");
    printf(" chay tren %s\n", b.location);
}
void numberOfSeat(struct taxi a)
{
    printf("\nSo cho ngoi cua xe taxi: %d\n", a.seat);
}
int calculation(struct taxi a)
{
    int n;
    if (a.seat == 4)
    {
        if (a.distance > 10)
            n = 9;
        else if (a.distance >= 6)
            n = 11;
        else
            n = 12;
    }
    if (a.seat == 7)
    {
        if (a.distance > 10)
            n = 10;
        else if (a.distance >= 6)
            n = 14;
        else
            n = 15;
    }
    return n;
}
int main()
{
    struct taxi a, b;
    FILE *file;
    file = fopen("bai4.txt", "r");
    char scan[100];
    if (file == NULL)
    {
        printf("Khong the mo file\n");
        return 0;
    }
    else
    {
        fgets(scan, sizeof scan, file);
        terminateNewLine(scan);
        strcpy(a.code, scan);
        fgets(scan, sizeof scan, file);
        terminateNewLine(scan);
        strcpy(a.name, scan);
        fgets(scan, sizeof scan, file);
        terminateNewLine(scan);
        strcpy(a.location, scan);
        fgets(scan, sizeof scan, file);
        a.distance = atoi(scan);
        fgets(scan, sizeof scan, file);
        a.seat = atoi(scan);
    }
    fclose(file);
    display(a);
    input(&b);
    display(b);
    checkCode(a, b);
    checkLocation(a, b);
    numberOfSeat(b);
    printf("\nTien xe taxi: %d\n", calculation(b));
    return 0;
}
