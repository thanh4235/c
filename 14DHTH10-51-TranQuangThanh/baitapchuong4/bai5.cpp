#include <stdio.h>

// Hàm kiểm tra số nguyên tố
int isPrime(int num)
{
    if (num < 2)
    {
        return 0; // Không phải số nguyên tố
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0; // Không phải số nguyên tố
        }
    }
    return 1; // Là số nguyên tố
}

int main()
{
    int n;

    // Nhập số nguyên n từ người dùng
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Nhap n phai lon hon 0.\n");
        return 1; // Kết thúc chương trình với mã lỗi
    }

    printf("%d so nguyen to dau tien la:\n", n);

    int count = 0; // Biến đếm số nguyên tố đã tìm thấy
    int i = 2;     // Bắt đầu kiểm tra từ số 2

    while (count < n)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
            count++;
        }
        i++;
    }

    return 0; // Kết thúc chương trình thành công
}