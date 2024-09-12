#include <stdio.h>
#include <math.h>
struct point
{
    float x;
    float y;
};
void input(struct point *first)
{
    printf("Enter x: ");
    scanf("%f", &first->x);
    printf("Enter y: ");
    scanf("%f", &first->y);
}
void output(struct point first)
{
    printf("Output:(%.2f,%.2f)\n", first.x, first.y);
}
void check(struct point first)
{
    if (first.x == 0 && first.y != 0)
        printf("Diem nam tren truc tung\n");
    if (first.x != 0 && first.y == 0)
        printf("Diem nam tren truc hoanh\n");
    if (first.x == 0 && first.y == 0)
        printf("Diem nam ngay tam O\n");
    if (first.x != 0 && first.y != 0)
        printf("Diem khong nam tren truc tung hay truc hoanh\n");
}
float distance(struct point first, struct point second)
{
    return sqrt(pow(second.x - first.x, 2) + pow(second.y - first.y, 2));
}
void research(struct point first)
{
    // đối xứng nhau qua trục hoành -> hoành độ bằng nhau, tung độ đối nhau
    printf("Tọa độ điểm đối xứng qua trục hoành là: (%.2f,%.2f)\n", first.x, -first.y);
    // đối xứng nhau qua trục tung -> tung độ bằng nhau, hoành độ đối nhau
    printf("Tọa độ điểm đối xứng qua trục tung là: (%.2f,%.2f)\n", -first.x, first.y);
    // đối xứng nhau qua gốc O -> hoành độ đối nhau, tung độ đối nhau
    printf("Tọa độ điểm đối xứng qua gốc O là: (%.2f,%.2f)\n", -first.x, -first.y);
}
float distance_O(struct point first)
{
    return sqrt(pow(first.x, 2) + pow(first.y, 2));
}
int main()
{
    point first, second;
    input(&first);
    output(first);
    check(first);
    input(&second);
    output(second);
    check(second);
    printf("Khoang cach giua 2 diem la: %.2f\n", distance(first, second));
    research(first);
    printf("Khonang cach tu diem do toi goc toa do O la: %.2f", distance_O(first));
    return 0;
}