#include <stdio.h>
#include <conio.h>
#include <string.h>

void input(int mang[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}
int check(int mang[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (mang[i] % 2 == 0 && mang[i + 1] % 2 == 0)
        {
            return 1;
        }
    }
    return 0;
}
void arrangement(int mang[], int n)
{
    int x;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (mang[i] > mang[j])
            {
                x = mang[i];
                mang[i] = mang[j];
                mang[j] = x;
            }
}
void terminateNewLine(char *a)
{
    char *newline = strchr(a, '\n');
    if (newline != NULL)
        *newline = '\0';
}
bool symmetry(char *mang)
{
    char x[100];
    int size2 = strlen(mang);
    for (int i = 0; i < strlen(mang); i++)
    {
        if (mang[i] != mang[size2 - 1])
        {
            return false;
        }
        size2--;
    }
    return true;
}
int main()
{
    char name[100];
    printf("Nhap: ");
    fgets(name, sizeof name, stdin);
    terminateNewLine(name);
    // if (symmetry(name))
    //     printf("\nCO");
    // else
    //     printf("\nKHONG");
    printf("\n%zu", strlen(name));

    return 0;
}