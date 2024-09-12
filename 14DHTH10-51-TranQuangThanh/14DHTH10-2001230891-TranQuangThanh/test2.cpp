#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Cấu trúc dữ liệu bệnh nhân
typedef struct {
    int maBenhNhan;
    char hoTen[100];
    int namSinh;
} BenhNhan;

// Cấu trúc node trong hàng đợi
typedef struct Node {
    BenhNhan data;
    struct Node* next;
} Node;

// Cấu trúc hàng đợi
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Khởi tạo hàng đợi
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Kiểm tra hàng đợi có rỗng không
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Thêm bệnh nhân vào hàng đợi
void enqueue(Queue* q, BenhNhan bn) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = bn;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Xóa bệnh nhân khỏi hàng đợi
BenhNhan dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        exit(1);
    }
    Node* temp = q->front;
    BenhNhan bn = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return bn;
}

// Hiển thị thông tin bệnh nhân đầu hàng đợi
void displayFront(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return;
    }
    BenhNhan bn = q->front->data;
    printf("Benh nhan dau hang doi: Ma Benh Nhan: %d, Ho Ten: %s, Nam Sinh: %d\n", bn.maBenhNhan, bn.hoTen, bn.namSinh);
}

// Hiển thị danh sách bệnh nhân trong hàng đợi
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("Ma Benh Nhan: %d, Ho Ten: %s, Nam Sinh: %d\n", temp->data.maBenhNhan, temp->data.hoTen, temp->data.namSinh);
        temp = temp->next;
    }
}

// Đếm số lượng bệnh nhân trong hàng đợi
int countPatients(Queue* q) {
    int count = 0;
    Node* temp = q->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Tính tuổi của bệnh nhân
int calculateAge(int birthYear) {
    time_t t = time(NULL);
    struct tm tm;
    localtime_s(&tm, &t);
    return tm.tm_year + 1900 - birthYear;
}

// Cho biết bệnh nhân phải đợi bao nhiêu bệnh nhân
int waitForTurn(Queue* q, char* hoTen) {
    int count = 0;
    Node* temp = q->front;
    while (temp != NULL) {
        if (strcmp(temp->data.hoTen, hoTen) == 0) {
            return count;
        }
        count++;
        temp = temp->next;
    }
    return -1; // Không tìm thấy bệnh nhân
}

// Chèn bệnh nhân vào đầu hàng đợi
void enqueuePriority(Queue* q, BenhNhan bn) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = bn;
    newNode->next = q->front;
    q->front = newNode;
    if (q->rear == NULL) {
        q->rear = newNode;
    }
}

// Kiểm tra hàng đợi có trẻ em không
int hasChild(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        if (calculateAge(temp->data.namSinh) <= 5) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Kiểm tra hàng đợi có bệnh nhân tên "Nguyen Hong Nhung" hay không
int hasPatientByName(Queue* q, char* hoTen) {
    Node* temp = q->front;
    while (temp != NULL) {
        if (strcmp(temp->data.hoTen, hoTen) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Hàm chính
int main() {
    Queue q;
    initQueue(&q);

    int choice;
    do {
        printf("\n1. Them benh nhan vao hang doi\n");
        printf("2. Xoa benh nhan khoi hang doi\n");
        printf("3. Hien thi danh sach benh nhan\n");
        printf("4. Hien thi thong tin benh nhan dau hang doi\n");
        printf("5. Cho biet so luong benh nhan trong hang doi\n");
        printf("6. Tim benh nhan va cho biet so nguoi phai doi\n");
        printf("7. Them benh nhan, neu <= 2 tuoi thi chen vao dau hang doi\n");
        printf("8. Kiem tra hang doi co tre em khong\n");
        printf("9. Kiem tra hang doi co benh nhan 'Nguyen Hong Nhung' khong\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Để loại bỏ ký tự '\n' sau khi nhập lựa chọn

        switch (choice) {
            case 1: {
                BenhNhan bn;
                printf("Nhap ma benh nhan: ");
                scanf("%d", &bn.maBenhNhan);
                printf("Nhap ho va ten benh nhan: ");
                getchar(); // Để loại bỏ ký tự '\n' sau khi nhập mã bệnh nhân
                fgets(bn.hoTen, 100, stdin);
                bn.hoTen[strcspn(bn.hoTen, "\n")] = 0; // Xóa bỏ ký tự '\n' ở cuối chuỗi
                printf("Nhap nam sinh: ");
                scanf("%d", &bn.namSinh);
                enqueue(&q, bn);
                break;
            }
            case 2: {
                if (!isEmpty(&q)) {
                    BenhNhan bn = dequeue(&q);
                    printf("Da xoa benh nhan: Ma Benh Nhan: %d, Ho Ten: %s, Nam Sinh: %d\n", bn.maBenhNhan, bn.hoTen, bn.namSinh);
                }
                break;
            }
            case 3:
                displayQueue(&q);
                break;
            case 4:
                displayFront(&q);
                break;
            case 5:
                printf("So luong benh nhan trong hang doi: %d\n", countPatients(&q));
                break;
            case 6: {
                printf("Nhap ho va ten benh nhan: ");
                char hoTen[100];
                fgets(hoTen, 100, stdin);
                hoTen[strcspn(hoTen, "\n")] = 0; // Xóa bỏ ký tự '\n' ở cuối chuỗi
                int waitCount = waitForTurn(&q, hoTen);
                if (waitCount == -1) {
                    printf("Khong tim thay benh nhan\n");
                } else {
                    printf("Benh nhan phai doi %d nguoi\n", waitCount);
                }
                break;
            }
            case 7: {
                BenhNhan bn;
                printf("Nhap ma benh nhan: ");
                scanf("%d", &bn.maBenhNhan);
                getchar(); // Để loại bỏ ký tự '\n' sau khi nhập mã bệnh nhân
                printf("Nhap ho va ten benh nhan: ");
                fgets(bn.hoTen, 100, stdin);
                bn.hoTen[strcspn(bn.hoTen, "\n")] = 0; // Xóa bỏ ký tự '\n' ở cuối chuỗi
                printf("Nhap nam sinh: ");
                scanf("%d", &bn.namSinh);
                if (calculateAge(bn.namSinh) <= 2) {
                    enqueuePriority(&q, bn);
                } else {
                    enqueue(&q, bn);
                }
                break;
            }
            case 8:
                if (hasChild(&q)) {
                    printf("Hang doi co tre em\n");
                } else {
                    printf("Hang doi khong co tre em\n");
                }
                break;
            case 9:
                if (hasPatientByName(&q, "Nguyen Hong Nhung")) {
                    printf("Hang doi co benh nhan 'Nguyen Hong Nhung'\n");
                } else {
                    printf("Hang doi khong co benh nhan 'Nguyen Hong Nhung'\n");
                }
                break;
            case 0:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
