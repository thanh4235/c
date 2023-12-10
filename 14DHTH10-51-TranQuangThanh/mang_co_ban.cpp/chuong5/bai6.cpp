// Viết chương trình để nhập ma trận 2x3, và trừ tất cả các phần tử 2 đơn vị
#include <stdio.h>

int main()
{
    // Khai báo ma trận 2x3
    int matrix[2][3];

    // Nhập giá trị cho ma trận
    printf("Nhap ma tran 2x3:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Nhap phan tu matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Trừ 2 đơn vị từ mỗi phần tử của ma trận
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] -= 2;
        }
    }

    // Hiển thị ma trận sau khi trừ 2 đơn vị
    printf("\nMa tran sau khi tru 2 don vi:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}