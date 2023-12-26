#include <stdio.h>
#include <string.h>
void terminateNewLine(char *a)
{
    char *newline = strchr(a, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
}
int main()
{
    char a[100], d[100], c[100];
    int b;
    printf("Nhap a: ");
    fgets(a, sizeof a, stdin);
    terminateNewLine(a);

    printf("Nhap b: ");
    scanf("%s", d);

    getchar();
    printf("Nhap c: ");
    fgets(c, sizeof c, stdin);
    terminateNewLine(a);

    printf("\n%s\n%d\n%s", a, b, c);
}