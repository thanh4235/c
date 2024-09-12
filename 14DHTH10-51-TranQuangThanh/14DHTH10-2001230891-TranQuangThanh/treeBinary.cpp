#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct tNode
{
    int info;
    tNode *left;
    tNode *right;
};

struct bTree
{
    tNode *root;
};

void initBTree(bTree &bt)
{
    bt.root = NULL;
}

tNode *createTNode(int x)
{
    tNode *p = new tNode;

    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat nut moi!");
        getch();
        return NULL;
    }
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int isEmpty(bTree bt)
{
    if (bt.root == NULL)
        return 1;
    else
        return 0;
}

int insertTNode(tNode *&root, int x)
{
    if (root == NULL)
    {
        root = createTNode(x);
        return 0;
    }
    if (root->info == x)
    {
        printf("\nPhần tử đã có sẵn trong cây");
        return 0;
    }
    if (x < root->info)
        insertTNode(root->left, x);
    else
        insertTNode(root->right, x);
    return 1;
}

int insertTNodeNoRecursion(tNode *&root, int x)
{
    tNode *p, *q, *r;
    p = createTNode(x);
    if (root == NULL)
    {
        root = p;
        return 1;
    }
    q = root;
    r = NULL;
    while (q != NULL)
    {
        if (q->info == x)
            return 0;
        r = q;
        if (p->info > q->info)
        {
            q = q->right;
        }
        else if (p->info < q->info)
        {
            q = q->left;
        }
    }
    if (r->info > x)
        r->left = p;
    else
        r->right = p;
    return 1;
}

// Tạo cây từ mảng a có sẵn dữ liệu
void createBTreeFromArray(bTree &bt, int a[], int n)
{
    initBTree(bt);
    for (int i = 0; i < n; i++)
    {
        insertTNode(bt.root, a[i]);
    }
}

// tìm bằng cách đệ quy
tNode *findTNode(tNode *root, int x)
{
    if (root == NULL)
        return NULL;
    if (root->info == x)
        return root;
    else if (root->info > x)
        return (findTNode(root->left, x));
    else
        return (findTNode(root->right, x));
}

// tìm bằng cách không đệ quy
tNode *findTNodeNoRecursion(tNode *root, int x)
{
    tNode *p = root;
    while (p != NULL)
    {
        if (p->info == x)
            return p;
        else if (p->info > x)
            p = p->left;
        else
            p = p->left;
    }
    return NULL;
}

tNode *findTNodeReplace(tNode *&p)
{
    tNode *f = p;
    tNode *q = p->right;
    while (q->left != NULL)
    {
        f = q;
        q = q->left;
    }
    p->info = q->info;
    if (f == p)
        f->right = q->right;
    else
        f->left = q->right;
    return q;
}

int deleteTNodeX(tNode *&root, int x)
{
    if (root == NULL)
        return 0;
    if (root->info > x)
        return deleteTNodeX(root->left, x);
    else if (root->info < x)
        return deleteTNodeX(root->right, x);
    else
    {
        tNode *p = root;
        if (root->left == NULL)
        {
            root = root->right;
            delete p;
        }
        else if (root->right == NULL)
        {
            root = root->right;
            delete p;
        }
        else
        {
            tNode *q = findTNodeReplace(p);
            delete q;
        }
    }
    return 1;
}

int deleteTree(tNode *&root)
{
    if (root == NULL)
        return 0;
    deleteTree(root->left);
    deleteTree(root->right);
    delete (root);
    return 1;
}

void traverseNLR(tNode *root)
{
    if (root == NULL)
        return;
    printf("%4d", root->info); // Xử lí thông tin nút gốc
    traverseNLR(root->left);
    traverseNLR(root->right);
}

void traverseLNR(tNode *root)
{
    if (root == NULL)
        return;
    traverseLNR(root->left);
    printf("%4d", root->info); // Xử lí thông tin nút gốc
    traverseLNR(root->right);
}

void traverseLRN(tNode *root)
{
    if (root == NULL)
        return;
    traverseLRN(root->left);
    traverseLRN(root->right);
    printf("%4d", root->info); // Xử lí thông tin nút gốc
}

// NRL, RNL, RLN

void traverseNRL(tNode *root)
{
    if (root == NULL)
        return;
    printf("%4d", root->info);
    traverseNRL(root->right);
    traverseNRL(root->left);
}

void traverseRNL(tNode *root)
{
    if (root == NULL)
        return;
    traverseRNL(root->right);
    printf("%4d", root->info);
    traverseRNL(root->left);
}

void traverseRLN(tNode *root)
{
    if (root == NULL)
        return;
    traverseRLN(root->right);
    traverseRLN(root->left);
    printf("%4d", root->info);
}

int height(struct tNode* root) {
    if (root == NULL||(root->left==NULL&&root->right==NULL)) {
        return 0;
    } else {
        // Tính chiều cao của cây con bên trái và cây con bên phải
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Trả về chiều cao lớn nhất giữa hai cây con và cộng thêm 1 cho nút hiện tại
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

int main()
{
    bTree binaryTree;
    initBTree(binaryTree);

    while (true)
    {
        printf("\n======== MENU ========\n");
        printf("Nhập (1)\n");
        printf("Xóa (2)\n");
        printf("Tìm (3)\n");
        printf("Xuất (4)\n");
        printf("Kết thúc (0)\n");
        printf("=======================\n");

        int data, choice;
        printf("\nNhập lựa chọn: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Thoát khỏi chương trình!\n");
            exit(0);
        case 1:
            printf("Nhập giá trị muốn thêm vào cây: ");
            scanf("%d", &data);
            insertTNode(binaryTree.root, data);
            break;
        case 2:
            printf("Nhập số cần xóa: ");
            scanf("%d", &data);
            if (deleteTNodeX(binaryTree.root, data))
                printf("\nĐã xóa thành công");
            else
                printf("\nKhông có tồn tại trong cây");
            break;
        case 3:
            printf("Nhập số cần tìm: ");
            scanf("%d", &data);
            if (findTNode(binaryTree.root, data) != NULL)
                printf("\nSố có tồn tại trong cây");
            else
                printf("\nSố không có tồn tại trong cây");
            break;
        case 4:
            printf("\nLNR:");
            traverseLNR(binaryTree.root);
            printf("\nLRN:");
            traverseLRN(binaryTree.root);
            printf("\nNLR:");
            traverseNLR(binaryTree.root);
            printf("\nNRL:");
            traverseNRL(binaryTree.root);
            printf("\nRLN:");
            traverseRLN(binaryTree.root);
            printf("\nRNL:");
            traverseRNL(binaryTree.root);
            break;
        case 5:
        printf("Chiều cao của cây nhị phân là: %d\n", height(binaryTree.root));
        break;
        default:
            printf("Lựa chọn không hợp lệ.\n");
        }
    }

    return 0;
}