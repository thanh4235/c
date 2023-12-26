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
    int a;
    do
    {
        printf("Nhap a: ");
        scanf("%d", &a);
        if (a != 4 && a != 7)
            printf("Chi co xe 4 cho hoac 7 cho\n");
    } while (a != 4 && a != 7);
    return 0;
}