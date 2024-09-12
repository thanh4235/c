#include <stdio.h>

#define LH -1 // Cây con trái cao hơn (lệch trái)
#define EH 0  // Cây con trái bằng cây con phải (cân bằng)
#define RH 1  // Cây con phải cao hơn (lệch phải)

struct AVLNode
{
    int balFactor;
    int info;
    AVLNode *left;
    AVLNode *right;
};

struct AVLTree
{
    AVLNode *root;
};

// Việc cân bằng lại cây trong trường hợp LB hoàn toàn giống như LL
void rotateLL(AVLNode *&T)
{
    AVLNode *T1 = T->left;
    T->left = T1->right;
    T1->right = T;
    switch (T1->balFactor)
    {
    case LH: // cây T1 lệch trái
        T1->balFactor = EH;
        T1->balFactor = EH;
        break;
    case EH: // cây T1 cân bằng
        T->balFactor = LH;
        T1->balFactor = RH;
        break;
    }
    T = T1;
}

void rotateLR(AVLNode *&T)
{
    AVLNode *T1 = T->left;
    AVLNode *T2 = T1->right;
    T1->right = T2->left;
    T2->left = T1;
    T->left = T2->right;
    T2->right = T;
    switch (T2->balFactor)
    {
    case LH:
        T->balFactor = RH;
        T1->balFactor = EH;
        break;
    case EH:
        T->balFactor = EH;
        T1->balFactor = EH;
        break;
    case RH:
        T->balFactor = EH;
        T1->balFactor = LH;
        break;
    }
    T2->balFactor = EH;
    T = T2;
}

void rotateRL(AVLNode *&T)
{
    AVLNode *T1 = T->right;
    AVLNode *T2 = T1->left;
    T1->left = T2->right;
    T2->right = T1;
    T->right = T2->left;
    T2->left = T;
    switch (T2->balFactor)
    {
    case RH:
        T->balFactor = LH;
        T1->balFactor = EH;
        break;
    case EH:
        T->balFactor = EH;
        T1->balFactor = EH;
        break;
    case LH:
        T->balFactor = EH;
        T1->balFactor = RH;
        break;
    }
    T2->balFactor = EH;
    T = T2;
}

void rotateRR(AVLNode *&T)
{
    AVLNode *T1 = T->right;
    T->right = T1->left;
    T1->left = T;
    switch (T1->balFactor)
    {
    case RH: // cây T1 lệch phải
        T->balFactor = EH;
        T1->balFactor = EH;
        break;
    case EH: // cây T1 cân bằng
        T->balFactor = RH;
        T1->balFactor = LH;
        break;
    }
    T = T1;
}

// Cân bằng lại cây AVL khi bị mất cân bằng
int balanceLeft(AVLNode *&T)
{
    // Khi cây T lệch bên trái cần cân bằng lại
    AVLNode *T1 = T->left;
    if (T1 == NULL)
        return 0;
    switch (T1->balFactor)
    {
    case LH:
        rotateLL(T);
        return 2;
    case EH:
        rotateLL(T);
        return 1;
    case RH:
        rotateLR(T);
        return 2;
    }
    return 0; // Thực hiện không thành công
}

int balanceRight(AVLNode *&T)
{
    // Khi cây T lệch bên phải cần cân bằng lại
    AVLNode *T1 = T->right;
    switch (T1->balFactor)
    {
    case LH:
        rotateRL(T);
        return 2;
    case EH:
        rotateRR(T);
        return 1;
    case RH:
        rotateRR(T);
        return 2;
    }
    return 0; // Thực hiện không thành công
}

int insertAVLNode(AVLNode *&T, int x)
{
    if (T == NULL)
    {
        T = new AVLNode;
        T->info = x;
        T->left = T->right = NULL;
        T->balFactor = EH;
        return 2;
    }
    if (x < T->info)
    {
        int Result = insertAVLNode(T->left, x);
        if (Result < 2)
            return Result;
        switch (T->balFactor)
        {
        case LH:
            T->balFactor = EH;
            return 1;
        case EH:
            T->balFactor = RH;
            return 2;
        case RH:
            return balanceRight(T);
        }
    }
    else if (x > T->info)
    {
        int Result = insertAVLNode(T->right, x);
        if (Result < 2)
            return Result;
        switch (T->balFactor)
        {
        case RH:
            T->balFactor = EH;
            return 1;
        case EH:
            T->balFactor = LH;
            return 2;
        case LH:
            return balanceLeft(T);
        }
    }
    else
    {
        return 0; // Node đã tồn tại
    }
}

int searchStandFor(AVLNode *&p, AVLNode *&q)
{
    int Result;
    if (q->left != NULL)
    {
        Result = searchStandFor(p, q->left);
        if (Result < 2)
            return Result;
        switch (q->balFactor)
        {
        case LH:
            q->balFactor = EH;
            return 2;
        case EH:
            q->balFactor = RH;
            return 1;
        case RH:
            return balanceRight(q);
        }
    }
    else
    {
        p->info = q->info;
        p = q;
        q = q->right;
    }
    return 2;
}

int deleteAVLNode(AVLNode *&T, int x)
{
    // Xóa nút có info bằng với x
    int Result;
    if (T == NULL)
        return 0; // Thực hiện không thành công
    if (T->info > x)
    {
        Result = deleteAVLNode(T->left, x);
        if (Result < 2)
            return Result;
        switch (T->balFactor)
        {
        case LH:
            T->balFactor = EH;
            return 2;
        case EH:
            T->balFactor = RH;
            return 1;
        case RH:
            return balanceRight(T);
        }
    }
    else if (T->info < x)
    {
        Result = deleteAVLNode(T->right, x);
        if (Result < 2)
            return Result;
        switch (T->balFactor)
        {
        case RH:
            T->balFactor = EH;
            return 2;
        case EH:
            T->balFactor = LH;
            return 1;
        case LH:
            return balanceLeft(T);
        }
    }
    else
    {
        AVLNode *p = T;
        if (T->left == NULL)
        {
            T = T->right;
            Result = 2;
        }
        else
        {
            if (T->right == NULL)
            {
                T = T->left;
                Result = 2;
            }
            else
            {
                Result = searchStandFor(p, T->right);
                if (Result < 2)
                    return Result;
                switch (T->balFactor)
                {
                case RH:
                    T->balFactor = EH;
                    return 2;
                case EH:
                    T->balFactor = LH;
                    return 1;
                case LH:
                    return balanceLeft(T);
                }
            }
        }
        delete p;
        return Result;
    }
    return Result;
}

void createAVLTree(AVLNode *&T, int n)
{
    int x;
    int Result, i = 1;
    do
    {
        printf("Tạo nút thứ %d có giá trị: ", i);
        scanf("%d", &x);
        Result = insertAVLNode(T, x);
        if (Result != 0)
            i++;
    } while (i <= n);
}

void displayInorder(struct AVLNode *T)
{
    if (T != NULL)
    {
        displayInorder(T->left);
        printf("%d ", T->info);
        displayInorder(T->right);
    }
}

int main()
{
    struct AVLTree tree;
    tree.root = NULL;
    int choice, value, n;
    do
    {
        printf("1. Thêm\n");
        printf("2. Xóa\n");
        printf("3. Duyệt\n");
        printf("0. Thoát\n");
        printf("Nhập lựa chọn: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nhập giá trị cần thêm: ");
            scanf("%d", &value);
            insertAVLNode(tree.root, value);
            break;
        case 2:
            printf("Nhập giá trị cần xóa: ");
            scanf("%d", &value);
            deleteAVLNode(tree.root, value);
            break;
        case 3:
            printf("Duyệt: ");
            displayInorder(tree.root);
            printf("\n");
            break;
        case 0:
            printf("Thoát chương trình!\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 0);
    return 0;
}
