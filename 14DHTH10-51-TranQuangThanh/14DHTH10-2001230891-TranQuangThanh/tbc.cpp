#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
	int info;
	node* next;
};
struct slist {
	node* head;
	node* tail;
};
node* createnode(int n) {
	node* p = (node*)malloc(sizeof(node));
	p->info = n;
	p->next = NULL;
	return p;
}

node *createNode(int x)
{
    node *p = new node;
    if (p == NULL)
    {
        printf("Không đủ bộ nhớ để cấp phát nút mới!");
        getch();
        return NULL;
    }
    p->info = x;
    p->next = NULL;
    return p;
}

void initslist(slist& sl) {
	sl.head = NULL;
	sl.tail = NULL;
}
void in(slist sl) {
	node* p = sl.tail;
	while (p != NULL) {
		printf("%d", p->info);
		p = p->next;
	}
	printf("\n");
}
int inserttail(slist &sl, int n) {
	node* p = createnode(n);
	if (p == NULL)
        return 0;
	if (sl.head == NULL) {
		sl.head = sl.tail = p;
	}
	else {
		sl.tail->next=p;
		sl.tail=p;
	}
	return 1;
}


// Tinh tong 2pt cuoi
//int tong2pt(slist sl) {
//	int tong;
//	for (node* p = sl.head; p != NULL; p = p->next) {
//		if (p->next == sl.tail)
//			tong = p->info;
//	}
//	return tong + sl.tail->info;
//}
// kiem tra ds c� chia to�n so chia het cho 5 hay kh�ng
//int kiem_tra(slist sl) {
//	node* p = sl.head;
//	while (p != NULL) {
//		if (p->info % 5 != 0)
//			return 0;
//		p = p->next;
//	}
//	return 1;
//}
// xuat ra c�c dia chi node c� gi� tri bang x
//void xuat(slist sl, int x) {
//	for (node* p = sl.head; p != NULL; p = p->next) {
//		if (p->info == x)
//			printf("%x\n", p);
//	}
//}
float trungbinhcong(slist sl, int x) {
	float tong = 0;
	int dem = 0;
	node* p = sl.head;
	while (p != NULL) {
		if (p->info > x) {
			tong += p->info;
		}
		p = p->next;
	}
	return (tong / dem);
}

float trungBinhCong(slist sl, float x){
    node* temp=sl.head;
    float tong=0;
    int dem=0;
    while(temp!=NULL){
        if(temp->info>x){
            tong+=temp->info;
            ++dem;
        }
        temp=temp->next;
    }
    if(dem==0) return 0;
    return (tong/dem);
}

int main() {
	slist sl;
	initslist(sl);
	inserttail(sl,7);
	inserttail(sl, 1);
	inserttail(sl, 4);
	inserttail(sl, 5);
	inserttail(sl, 2);

	/*printf("%d", tong2pt(sl));*/
	
	/*int x;
	printf("nhap x:");
	scanf_s("%d", &x);
	xuat(sl,x);*/
	int x;
	printf("nhap x:");
	scanf_s("%d", &x);
	printf("trung binh cong: %f", trungBinhCong(sl, x));

	return 0;
}
