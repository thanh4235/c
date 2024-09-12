#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char code[10];
};
int main()
{
    struct student a[100];
    int i, count = 0;

    FILE *file;
    file = fopen("moFile.txt", "r");
    char scan[100];
    if (file == NULL)
    {
        printf("Khong the mo file!\n");
        return 0;
    }
    else
    {
        while (fscanf(file, "%s", scan) != EOF)
        {
            fgets(scan, sizeof scan, stdin);
            strcpy(a[i].code, scan);
            i++;
        }
    }
    fclose(file);
    // int min = strlen(a[0].code), max = strlen(a[0].code);
    // char strMin[100], strMax[100];
    // for (int i = 1; a[i].code != NULL; i++)
    // {
    //     if (strlen(a[i].code) < min)
    //     {
    //         min = strlen(a[i].code);
    //         strcpy(strMin, a[i].code);
    //     }
    //     if (strlen(a[i].code) > max)
    //     {
    //         max = strlen(a[i].code);
    //         strcpy(strMax, a[i].code);
    //     }
    // }
    // printf("\nChuoi it ki tu nhat la: %s\n", strMin);
    // printf("(Gom %d ki tu)\n", min);
    // printf("\nChuoi nhieu ki tu nhat la: %s\n", strMax);
    // printf("(Gom %d ki tu)\n", max);
    for (int j = 0; j < i; j++)
    {
        printf("\n%s", a[i].code);
    }
    return 0;
}