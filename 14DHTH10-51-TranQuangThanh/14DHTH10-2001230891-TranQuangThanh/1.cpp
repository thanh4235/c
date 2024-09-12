/*Cho mảng 1 chiều a chừa n số nguyên. Viết chương trình thực hiện các yêu cầu sau:
1. Viết hàm nhập/xuất mảng a
2. Tìm max/min của a
3. Đếm số phần tử chẵn/lẻ trong a
4. Tìm kiếm phần tử x trong a theo 2 dạng (trả về vị trí/ xuất câu thông báo) với giải thuật tìm kiếm tuyến tính/ tìm kiếm nhị phân
5. Đếm trên a có bao nhiêu phần tử x (x nhập từ bàn phím)*/

#include <iostream>

void input(int arr[], int n){
   for(int i=0;i<n;i++){
  std::cout << "Nhap phan tu thu " <<i+1<<": ";
  std::cin >> arr[i];
   }
}

int min(int arr[], int n){
   int min= arr[0];
   for(int i=1;i<n;i++){
  if(min>arr[i])
  min=arr[i];
   }
   return min;
}

int max(int arr[], int n){
   int max= arr[0];
   for(int i=1;i<n;i++){
  if(max<arr[i])
  max=arr[i];
   }
   return max;
}

void evenAndOddElements(int arr[], int n){
   std::cout<<"Cac phan tu chan:";
   for(int i=0;i<n;i++){
  if(arr[i]%2==0)
  std::cout<< " " << arr[i];
   }
   std::cout<< std::endl;

   std::cout<<"Cac phan tu le:";
   for(int i=0;i<n;i++){
  if(arr[i]%2!=0)
  std::cout<< " " << arr[i];
   }
   std::cout<< std::endl;
}

void findX(int arr[], int n){
   int x;
   std::cout << "Nhap X: ";
 std::cin >> x;
 std::cout<< "So " << x << " nam o vi tri phan tu thu";
 for(int i=0;i<n;i++){
  if(arr[i]==x)
  std::cout<<" "<< i+1;
   }
   std::cout<<" trong mang"<<std::endl;
}

void howManyX(int arr[], int n){
   int x, count=0;
   std::cout << "Nhap X: ";
 std::cin >> x;
 for(int i=0;i<n;i++){
  if(arr[i]==x)
  count++;
   }
   std::cout<<"Co tong cong "<<count<<" phan tu so "<<x<<" trong mang"<<std::endl;
}

void display(int arr[], int n){
   std::cout<< "Cac phan tu trong mang:";
   for(int i=0;i<n;i++){
      std::cout << " " << arr[i];
   }
}

int main() {
   int a[100],n;

 std::cout << "Nhap so luong phan tu: ";
 std::cin >> n;
   input(a,n);

   std::cout<< "Phan tu nho nhat trong mang: "<< min(a,n) << std::endl;
   std::cout<< "Phan tu lon nhat trong mang: "<< max(a,n) << std::endl;

evenAndOddElements(a,n);

howManyX(a,n);

findX(a,n);

   display(a,n);

  return 0;
}