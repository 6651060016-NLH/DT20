
#include<stdio.h>

struct Node {
    int data;
    Node *next;
};
typedef Node* pNode;

// Tạo node mới
pNode CreateNode(int x) {
    pNode p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Thêm đầu
pNode AddHead(pNode head, int x) {
    pNode p = CreateNode(x);
    if (head == NULL) {
        head = p;
    } else {
        p->next = head;
        head = p;
    }
    return head;
}

// Thêm cuối
pNode AddTail(pNode head, int x) {
    pNode p = CreateNode(x);
    if (head == NULL) return p;
    pNode q = head;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    return head;
}

// Thêm tại vị trí pos
pNode AddAt(pNode head, int x, int pos) {
    if (pos == 0 || head == NULL) {
        return AddHead(head, x);
    }
    pNode q = head;
    int i = 0;
    while (q != NULL && i < pos - 1) {
        q = q->next;
        i++;
    }
    if (q == NULL) return head;
    pNode p = CreateNode(x);
    p->next = q->next;
    q->next = p;
    return head;
}

// In danh sách
void PrintList(pNode head) {
    pNode p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Đếm số lần xuất hiện giá trị x
int Search(pNode head, int x) {
    int count = 0;
    pNode p = head;
    while (p != NULL) {
        if (p->data == x)
            count++;
        p = p->next;
    }
    return count;
}

// Sắp xếp tăng dần
pNode SortList(pNode head) {
    if (head == NULL) return head;
    for (pNode p = head; p->next != NULL; p = p->next) {
        for (pNode q = p->next; q != NULL; q = q->next) {
            if (p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    return head;
}

// Đếm số phần tử trong danh sách
int CountList(pNode head) {
    int cnt = 0;
    pNode p = head;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int main() {
    pNode head = NULL;
    int n, x, pos;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        printf("Nhap gia tri thu %d = ", i + 1);
        scanf("%d", &val);
        head = AddTail(head, val);
    }

    printf("\nDanh sach vua nhap: ");
    PrintList(head);

    printf("\nNhap gia tri X can dem: ");
    scanf("%d", &x);
    int kq = Search(head, x);
    if (kq > 0)
        printf("%d xuat hien %d lan trong danh sach\n", x, kq);
    else
        printf("%d khong co trong danh sach\n", x);

    printf("\nDanh sach sap xep tang dan: ");
    head = SortList(head);
    PrintList(head);

    printf("\nSo phan tu trong danh sach: %d\n", CountList(head));

    printf("\nNhap gia tri muon chen: ");
    scanf("%d", &x);
    printf("Nhap vi tri chen (0 la dau ds): ");
    scanf("%d", &pos);
    head = AddAt(head, x, pos);

    printf("\nDanh sach sau khi chen: ");
    PrintList(head);

    return 0;
}

