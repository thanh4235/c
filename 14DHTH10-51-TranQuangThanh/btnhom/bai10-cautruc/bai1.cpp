#include <stdio.h>

// Khai báo cấu trúc Point để mô tả một điểm trên toạ độ xOy
struct Point
{
    float x;
    float y;
};

// Hàm nhập thông tin cho một điểm
void nhapDiem(struct Point *p)
{
    printf("Nhap toa do x: ");
    scanf("%f", &p->x);

    printf("Nhap toa do y: ");
    scanf("%f", &p->y);
}

// Hàm xuất thông tin của một điểm
void xuatDiem(struct Point p)
{
    printf("Toa do x: %.2f\n", p.x);
    printf("Toa do y: %.2f\n", p.y);
}

int main()
{
    struct Point diem; // Khai báo một biến kiểu Point

    // Nhập thông tin cho điểm
    printf("Nhap thong tin cho diem:\n");
    nhapDiem(&diem);

    // Xuất thông tin của điểm
    printf("\nThong tin diem:\n");
    xuatDiem(diem);

    return 0;
}
