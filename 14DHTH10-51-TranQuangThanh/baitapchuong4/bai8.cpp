#include <stdio.h>

void docSo(int n)
{
    const char *hangDonVi[] = {"", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    const char *hangChuc[] = {"", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi"};
    const char *hangTram[] = {"", "mot tram", "hai tram", "ba tram", "bon tram", "nam tram", "sau tram", "bay tram", "tam tram", "chin tram"};

    if (n < 1 || n >= 1000)
    {
        printf("Vui long nhap so n lon hon 0 va nho hon 1000.\n");
        return;
    }

    int tram = n / 100;
    int chuc = (n % 100) / 10;
    int donVi = n % 10;

    printf("Cach doc so %d la: ", n);

    if (tram > 0)
    {
        printf("%s ", hangTram[tram]);
    }

    if (chuc > 1)
    {
        printf("%s ", hangChuc[chuc]);
        if (donVi > 0)
        {
            printf("%s ", hangDonVi[donVi]);
        }
    }
    else if (chuc == 1)
    {
        printf("muoi ");
        if (donVi > 0)
        {
            printf("%s ", hangDonVi[donVi]);
        }
    }
    else
    {
        if (donVi > 0)
        {
            printf("%s ", hangDonVi[donVi]);
        }
    }

    printf("\n");
}

int main()
{
    int n;

    // Nhập số nguyên n từ người dùng
    printf("Nhap so nguyen n (0 < n < 1000): ");
    scanf("%d", &n);

    // Gọi hàm để đọc số và xuất ra màn hình
    docSo(n);

    return 0;
}