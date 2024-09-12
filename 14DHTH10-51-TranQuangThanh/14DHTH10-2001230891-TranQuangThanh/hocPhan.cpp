/*Tạo một bảng băm với phương pháp địa chỉ mở để quản lý các học phần do khoa Công nghệ thông tin quản lý:
1. Mỗi học phần các thông tin: mã học phần, tên học phần, số tín chỉ, loại học phần, chủ nhiệm môn học, ngành.
2. Tạo bảng băm chứa thông tin học phần bằng 2 cách: nhập từ bàn phím và đọc/ghi từ file.txt
3. Thêm một phần tử vào trong bảng băm
4. Xóa một phần tử ra khỏi bảng băm
5. Tìm kiếm một phần tử trong bảng băm
6. Cập nhật thông tin của một phần tử trong bảng băm
7. Điều chỉnh lại kích thước (tăng gấp 2) của bảng băm khi vượt quá ngưỡng lưu trữ của bảng băm
8. Xuất tất cả các học phần mà có số tín chỉ lớn hơn x ra màn hình
9. Tính tổng số tín chỉ của các học phần của khoa Công nghệ thông tin
10. Đếm số lượng và tổng số tín chỉ theo từng loại học phần mà khoa Công nghệ thông tin quản lý*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 5 // Kích thước ban đầu của bảng băm

typedef struct
{
    char maHocPhan[50];
    char tenHocPhan[100];
    int soTinChi;
    char loaiHocPhan[50];
    char chuNhiem[100];
    char nganh[100];
} HocPhan;

typedef struct
{
    char maHocPhan[50];
    HocPhan hocPhan;
} hashNode;

hashNode *hashTable;
int n, currentSize;

int hashString(const char *str)
{
    int hash = 0;
    while (*str)
    {
        hash += *str++;
    }
    return hash;
}

int hashFunction(const char *key)
{
    return (hashString(key) % currentSize);
}

void initialize()
{
    currentSize = INITIAL_SIZE;
    hashTable = new hashNode[currentSize];
    for (int i = 0; i < currentSize; i++)
    {
        strcpy(hashTable[i].maHocPhan, "");
    }
    n = 0;
}

int isFull()
{
    return (n == currentSize);
}

void terminateNewLine(char *a)
{
    char *newline = strchr(a, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
}

int insert(const char *maHocPhan, HocPhan hocPhan)
{
    if (isFull())
    {
        // Tăng kích thước bảng lên gấp đôi
        currentSize *= 2;
        hashNode *newHashTable = new hashNode[currentSize];
        for (int i = 0; i < currentSize; i++)
        {
            strcpy(newHashTable[i].maHocPhan, ""); // Khởi tạo các khóa là chuỗi rỗng
        }
        for (int i = 0; i < n; i++)
        {
            if (strcmp(hashTable[i].maHocPhan, "") != 0)
            {
                int index = hashFunction(hashTable[i].maHocPhan);
                while (strcmp(newHashTable[index].maHocPhan, "") != 0)
                {
                    index = (index + 1) % currentSize;
                }
                strcpy(newHashTable[index].maHocPhan, hashTable[i].maHocPhan);
                newHashTable[index].hocPhan = hashTable[i].hocPhan;
            }
        }
        free(hashTable);
        hashTable = newHashTable;
    }

    int index = hashFunction(maHocPhan);
    int i = index;
    while (strcmp(hashTable[i].maHocPhan, "") != 0)
    {
        if (i > currentSize)
            currentSize *= 2;
        i = (i + 1) % currentSize; // Linear probing
    }

    strcpy(hashTable[i].maHocPhan, maHocPhan);
    hashTable[i].hocPhan = hocPhan;
    n++;
    return i;
}

void readFromFile(const char *fileName)
{
    HocPhan hp;
    FILE *file;
    file = fopen(fileName, "r");
    char buffer[256]; // Sử dụng buffer lớn hơn để đọc dữ liệu từ file
    if (file == NULL)
    {
        printf("Khong the mo file\n");
    }
    else
    {
        while (fgets(buffer, sizeof(buffer), file))
        {
            // Phân tích dữ liệu từ buffer và gán cho các trường của học phần
            char *token = strtok(buffer, ",");
            if (token != NULL)
            {
                strcpy(hp.maHocPhan, token);
                token = strtok(NULL, ",");
                if (token != NULL)
                {
                    strcpy(hp.tenHocPhan, token);
                    token = strtok(NULL, ",");
                    if (token != NULL)
                    {
                        hp.soTinChi = atoi(token);
                        token = strtok(NULL, ",");
                        if (token != NULL)
                        {
                            strcpy(hp.loaiHocPhan, token);
                            token = strtok(NULL, ",");
                            if (token != NULL)
                            {
                                strcpy(hp.chuNhiem, token);
                                token = strtok(NULL, ",");
                                if (token != NULL)
                                {
                                    terminateNewLine(token);
                                    strcpy(hp.nganh, token);
                                    // Thêm học phần vào bảng băm
                                    insert(hp.maHocPhan, hp);
                                }
                            }
                        }
                    }
                }
            }
        }
        fclose(file);
    }
}

void input(HocPhan *a)
{
    printf("\nVUI LONG NHAP DAY DU THONG TIN\n");
    printf("Nhap ma hoc phan: ");
    getchar();
    fgets(a->maHocPhan, sizeof a->maHocPhan, stdin);
    terminateNewLine(a->maHocPhan);
    printf("Nhap ten hoc phan: ");
    fgets(a->tenHocPhan, sizeof a->tenHocPhan, stdin);
    terminateNewLine(a->tenHocPhan);
    printf("Nhap so tin chi: ");
    scanf("%d", &a->soTinChi);

    printf("Nhap loai hoc phan: ");
    getchar();
    fgets(a->loaiHocPhan, sizeof a->loaiHocPhan, stdin);
    terminateNewLine(a->loaiHocPhan);
    printf("Nhap ten chu nhiem: ");
    fgets(a->chuNhiem, sizeof a->chuNhiem, stdin);
    terminateNewLine(a->chuNhiem);
    printf("Nhap ten nganh: ");
    fgets(a->nganh, sizeof a->nganh, stdin);
    terminateNewLine(a->nganh);
}

int search(const char *maHocPhan)
{
    int index = hashFunction(maHocPhan);
    int i = index;
    while (strcmp(hashTable[i].maHocPhan, "") != 0)
    {
        if (strcmp(hashTable[i].maHocPhan, maHocPhan) == 0)
        {
            return i;
        }
        i = (i + 1) % currentSize; // Linear probing
    }
    return -1;
}

void removeEntry(const char *maHocPhan)
{
    int index = search(maHocPhan);
    if (index != -1)
    {
        strcpy(hashTable[index].maHocPhan, ""); // Xóa mã học phần bằng cách đặt chuỗi rỗng
        n--;
    }
    else
    {
        printf("KHONG TIM THAY hoc phan co ma \"%s\" de xoa.\n", maHocPhan);
    }
}

void removeAll()
{
    for (int i = 0; i < currentSize; i++)
    {
        strcpy(hashTable[i].maHocPhan, ""); // Xóa mã học phần bằng cách đặt chuỗi rỗng
    }
    n = 0;
}

void updateEntry(const char *maHocPhan)
{
    int selection;
    int index = search(maHocPhan);
    if (index != -1)
    {
        do
        {
            printf("\nBan muon sua doi lai thong tin gi cua %s:\n", maHocPhan);
            printf("(1) Ma Hoc Phan\n");
            printf("(2) Ten Hoc Phan\n");
            printf("(3) So Tin Chi\n");
            printf("(4) Loai Hoc Phan\n");
            printf("(5) Chu Nhiem\n");
            printf("(6) Nganh\n");
            printf("(0) Huy\n");

            printf("Hay nhap lua chon: ");
            scanf("%d", &selection);
            switch (selection)
            {
            case 1:
                printf("SUA LAI MA HOC PHAN\n");
                printf("Nhap lai ma hoc phan: ");
                getchar();
                fgets(hashTable[index].hocPhan.maHocPhan, sizeof hashTable[index].hocPhan.maHocPhan, stdin);
                terminateNewLine(hashTable[index].hocPhan.maHocPhan);
                break;
            case 2:
                printf("SUA LAI TEN HOC PHAN\n");
                printf("Nhap lai ten hoc phan: ");
                getchar();
                fgets(hashTable[index].hocPhan.tenHocPhan, sizeof hashTable[index].hocPhan.tenHocPhan, stdin);
                terminateNewLine(hashTable[index].hocPhan.tenHocPhan);
                break;
            case 3:
                printf("SUA LAI SO TIN CHI\n");
                printf("Nhap lai so tin chi: ");
                scanf("%d", &hashTable[index].hocPhan.soTinChi);
                break;
            case 4:
                printf("SUA LAI LOAI HOC PHAN\n");
                printf("Nhap lai loai hoc phan: ");
                getchar();
                fgets(hashTable[index].hocPhan.loaiHocPhan, sizeof hashTable[index].hocPhan.loaiHocPhan, stdin);
                terminateNewLine(hashTable[index].hocPhan.loaiHocPhan);
                break;
            case 5:
                printf("SUA LAI TEN CHU NHIEM\n");
                printf("Nhap lai ten chu nhiem: ");
                getchar();
                fgets(hashTable[index].hocPhan.chuNhiem, sizeof hashTable[index].hocPhan.chuNhiem, stdin);
                terminateNewLine(hashTable[index].hocPhan.chuNhiem);
                break;
            case 6:
                printf("SUA LAI NGANH\n");
                printf("Nhap lai ten chu nhiem: ");
                getchar();
                fgets(hashTable[index].hocPhan.nganh, sizeof hashTable[index].hocPhan.nganh, stdin);
                terminateNewLine(hashTable[index].hocPhan.nganh);
                break;
            }
        } while (selection != 0);
    }
    else
    {
        printf("KHONG TIM THAY hoc phan co ma \"%s\" de cap nhat.\n", maHocPhan);
    }
}

void traverseByCredit(int x)
{
    printf("\nCac hoc phan co so tin chi lon hon %d:\n", x);
    printf("\n%-12s %-20s %-15s %-15s %-20s %-20s",
           "Ma hoc phan", "Ten hoc phan", "So tin chi", "Loai hoc phan", "Chu nhiem", "Nganh");
    for (int i = 0; i < currentSize; i++)
    {
        if (strcmp(hashTable[i].maHocPhan, "") != 0 && hashTable[i].hocPhan.soTinChi > x)
        {
            printf("\n%-12s %-20s %-15d %-15s %-20s %-20s",
                   hashTable[i].hocPhan.maHocPhan,
                   hashTable[i].hocPhan.tenHocPhan,
                   hashTable[i].hocPhan.soTinChi,
                   hashTable[i].hocPhan.loaiHocPhan,
                   hashTable[i].hocPhan.chuNhiem,
                   hashTable[i].hocPhan.nganh);
        }
    }
    printf("\n");
}

void traverseAll()
{
    printf("\n======== BANG BAM ========");
    printf("\n%-12s %-20s %-15s %-15s %-20s %-20s",
           "Ma hoc phan", "Ten hoc phan", "So tin chi", "Loai hoc phan", "Chu nhiem", "Nganh");
    for (int i = 0; i < currentSize; i++)
    {
        if (strcmp(hashTable[i].maHocPhan, "") != 0)
        {
            printf("\n%-12s %-20s %-15d %-15s %-20s %-20s",
                   hashTable[i].hocPhan.maHocPhan,
                   hashTable[i].hocPhan.tenHocPhan,
                   hashTable[i].hocPhan.soTinChi,
                   hashTable[i].hocPhan.loaiHocPhan,
                   hashTable[i].hocPhan.chuNhiem,
                   hashTable[i].hocPhan.nganh);
        }
    }
    printf("\n");
}

int sumCreditsInCNTT()
{
    int sum = 0;
    for (int i = 0; i < currentSize; i++)
    {
        if (strcmp(hashTable[i].maHocPhan, "") != 0 && strcmp(hashTable[i].hocPhan.nganh, "CNTT") == 0)
        {
            sum += hashTable[i].hocPhan.soTinChi;
        }
    }
    return sum;
}

void countAndSumByCourseType(int *count, int *sumCredits, const char *courseType)
{
    *count = 0;
    *sumCredits = 0;

    for (int i = 0; i < currentSize; i++)
    {
        if (strcmp(hashTable[i].maHocPhan, "") != 0 && strcmp(hashTable[i].hocPhan.loaiHocPhan, courseType) == 0)
        {
            (*count)++;
            *sumCredits += hashTable[i].hocPhan.soTinChi;
        }
    }
}

void showMenu()
{
    printf("\n****************************************************************");
    printf("\n*                             MENU                             *");
    printf("\n*==============================================================*");
    printf("\n* 1: Them hoc phan moi tu ban phim                             *");
    printf("\n* 2: Them cac hoc phan co san trong FILE                       *");
    printf("\n* 3: Xoa mot hoc phan                                          *");
    printf("\n* 4: Xoa toan bo hoc phan                                      *");
    printf("\n* 5: Tim kiem hoc phan                                         *");
    printf("\n* 6: Cap nhat lai thong tin hoc phan                           *");
    printf("\n* 7: Xuat tat ca cac hoc phan ma co so tin chi lon hon x       *");
    printf("\n* 8: Xuat toan bo hoc phan co trong bang bam                   *");
    printf("\n* 9: Tinh tong so tin chi cua cac hoc phan cua khoa CNTT       *");
    printf("\n* 10: Dem so luong va tong so tin chi theo tung loai hoc phan  *");
    printf("\n* 0: Ket thuc chuong trinh                                     *");
    printf("\n****************************************************************");
}

void process()
{
    int choice;
    char maHocPhan[50];

    do
    {
        showMenu();
        printf("\nNhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nNhap thong tin hoc phan moi:\n");
            HocPhan newSubject;
            input(&newSubject);
            insert(newSubject.maHocPhan, newSubject);
            break;
        case 2:
            printf("\nDoc danh sach hoc phan tu file!\n");
            readFromFile("hocPhan.txt");
            break;
        case 3:
            printf("\nNhap ma hoc phan muon xoa: ");
            scanf("%s", maHocPhan);
            removeEntry(maHocPhan);
            break;
        case 4:
            printf("\nXoa toan bo hoc phan!\n");
            removeAll();
            break;
        case 5:
            printf("\nNhap ma hoc phan muon tim kiem: ");
            scanf("%s", maHocPhan);
            if (search(maHocPhan) != -1)
            {
                printf("\nTim thay hoc phan co ma \"%s\" trong bang bam.\n", maHocPhan);
            }
            else
            {
                printf("\nKhong tim thay hoc phan co ma \"%s\" trong bang bam.\n", maHocPhan);
            }
            break;
        case 6:
            printf("\nNhap ma hoc phan muon cap nhat thong tin: ");
            scanf("%s", maHocPhan);
            updateEntry(maHocPhan);
            break;
        case 7:
            printf("\nNhap so tin chi x: ");
            int x;
            scanf("%d", &x);
            traverseByCredit(x);
            break;
        case 8:
            printf("\nDanh sach hoc phan co trong bang bam:\n");
            traverseAll();
            break;
        case 9:
            printf("\nTong so tin chi cua cac hoc phan cua khoa CNTT: %d\n", sumCreditsInCNTT());
            break;
        case 10:
            printf("\nDem so luong va tong so tin chi theo tung loai hoc phan:\n");
            int count;
            int sumCredits;
            countAndSumByCourseType(&count, &sumCredits, "Bat buoc");
            printf("\nBat buoc: %d hoc phan, tong so tin chi: %d\n", count, sumCredits);
            countAndSumByCourseType(&count, &sumCredits, "Tu chon");
            printf("Tu chon: %d hoc phan, tong so tin chi: %d\n", count, sumCredits);
            break;
        case 0:
            printf("\nKet thuc chuong trinh.\n");
            break;
        default:
            printf("\nLua chon khong hop le. Vui long chon lai.\n");
            break;
        }

    } while (choice != 0);
}

int main()
{
    initialize();

    process();

    free(hashTable);

    return 0;
}
