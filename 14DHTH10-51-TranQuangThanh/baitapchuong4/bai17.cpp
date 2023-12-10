#include <stdio.h>

int main()
{
    long N;
    printf("Nhap so nguyen lon N: ");
    scanf("%ld", &N);

    // Tìm chữ số hàng đầu tiên của N
    long firstDigit = N;
    while (firstDigit >= 10)
    {
        firstDigit /= 10;
    }
    printf("Chu so hang dau tien cua N la: %ld\n", firstDigit);

    // Tính tổng các chữ số của N
    long sum = 0;
    long tempN = N;
    while (tempN != 0)
    {
        sum += tempN % 10;
        tempN /= 10;
    }
    printf("Tong cac chu so cua N la: %ld\n", sum);

    // Tìm chữ số lớn nhất trong k chữ số
    long maxDigit = 0;
    tempN = N;
    while (tempN != 0)
    {
        long digit = tempN % 10;
        if (digit > maxDigit)
        {
            maxDigit = digit;
        }
        tempN /= 10;
    }
    printf("Chu so lon nhat trong cac chu so cua N la: %ld\n", maxDigit);

    // Đếm số chữ số của N
    int digitCount = 0;
    tempN = N;
    while (tempN != 0)
    {
        tempN /= 10;
        digitCount++;
    }
    printf("So chu so cua N la: %d\n", digitCount);

    // Kiểm tra xem N có các chữ số khác nhau đôi một không
    int uniqueDigits = 1;      // Giả sử là đúng (1) ban đầu
    long seenDigits[10] = {0}; // Mảng để theo dõi chữ số đã xuất hiện
    tempN = N;
    while (tempN != 0)
    {
        long digit = tempN % 10;
        if (seenDigits[digit] == 1)
        {
            uniqueDigits = 0; // Nếu chữ số đã xuất hiện, đặt là sai (0)
            break;
        }
        seenDigits[digit] = 1; // Đánh dấu chữ số đã xuất hiện
        tempN /= 10;
    }
    printf("N co chu so khac nhau doi mot khong? %s\n", uniqueDigits ? "Co" : "Khong");

    return 0;
}