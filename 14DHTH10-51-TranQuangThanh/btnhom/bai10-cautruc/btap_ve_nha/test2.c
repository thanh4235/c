#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    // char hello[5];
    // hello = "12345";   --->This wont compile

    char hello[100] = "12345.5465";

    // printf("My number is: %f", atoi(hello));
    char ho[100];
    strcpy(ho, hello);
    printf("\n%s", ho);

    return 0;
}