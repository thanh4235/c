#include <stdio.h>
int main()
{
  // khai bao a, b, kq
  int a, b, kq, step;
  // nhap a
  printf("nhap a:");
  scanf("%d", &a);
  // nhap b
  printf("nhap b:");
  scanf("%d", &b);
  // t́m step la so lon nhat giua a và b
  if (a > b) // neu a>b
  {
    step = a;
  }
  else // neu a<b
  {
    step = b;
  }

  for (int i = step; i <= a * b; i += step)
  {
    if (i % a == 0 && i % b == 0) // neu i chia het cho ca a va b
    {
      kq = i;
      break;
    }
  }
  // in ket qua ra man hinh
  printf("BCNN(%d, %d) = %d", a, b, kq);
}