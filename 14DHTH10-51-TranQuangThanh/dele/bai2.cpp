#include <stdio.h>
#include <conio.h>
int main()
{
    printf("Cac so co hai chu so là boi cua 5:\n");
    for (int i = 10; i < 100; i++)
        if (i % 5 == 0)
            printf("%d\n", i);
    getch();
    return 0;
}