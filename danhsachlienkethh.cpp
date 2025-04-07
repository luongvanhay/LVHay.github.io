#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
using node = Node*;

// Cấp phát động một node mới
node makeNode(int x) {
    node tmp = new Node; // Sửa lỗi "twp"
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Kiểm tra danh sách liên kết rỗng
bool empty(node a) {
    return a == NULL;
}

// Lấy kích thước của danh sách liên kết
int size(node a) {
    int cnt = 0;
    while (a != NULL) {
        cnt++;
        a = a->next;
    }
    return cnt;
}

// Thêm một node vào đầu danh sách liên kết
void chendau(node& a, int x) {
    node tmp = makeNode(x);
    tmp->next = a;
    a = tmp;
}

// Thêm một node vào cuối danh sách liên kết
void chencuoi(node& a, int x) {
    node tmp = makeNode(x);
    if (a == NULL) {
        a = tmp;
    }
    else {
        node p = a; 
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

// Thêm một phần tử vào giữa danh sách liên kết
void chengiua(node& a, int x, int pos) { 
    int n = size(a);
    if (pos <= 0 || pos > n + 1) { 
        cout << "Vi tri chen khong hop le!\n";
        return;
    }
    if (pos == 1) {
        chendau(a, x);
        return;
    }
    if (pos == n + 1) {
        chencuoi(a, x);
        return;
    }
    node p = a;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}

// Xóa một phần tử ở đầu danh sách liên kết
void deletedau(node& a) { 
    if (a == NULL) {
        cout << "Danh sach rong!\n";
        return;
    }
    a = a->next;
}

// Xóa một phần tử ở cuối danh sách liên kết
void deletecuoi(node& a) {
    if (a == NULL) return;
    node truoc = NULL, sau = a;
    while (sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) { // Danh sách chỉ có một phần tử
        a = NULL;
    }
    else {
        truoc->next = NULL; 
    }
}

// Xóa một phần tử ở giữa danh sách liên kết
void deletemidd(node& a, int pos) {
    if (pos <= 0 || pos > size(a)) return;
    node truoc = NULL, sau = a;
    for (int i = 1; i < pos; i++) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        a = a->next;
    }
    else {
        truoc->next = sau->next;
    }
}

// In danh sách liên kết
void in(node a) {
    cout << "-------------------------\n"; 
    while (a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n-------------------------\n";
}

int main() {
    node heap = NULL;
    while (1) {
		cout << "1. Chen dau\n";
		cout << "2. Chen cuoi\n";
		cout << "3. Chen giua\n";
		cout << "4. Xoa dau\n";
		cout << "5. Xoa cuoi\n";
		cout << "6. Xoa giua\n";
		cout << "7. In danh sach\n";
        cout << " Moi ban chon:";

        int lc; cin >> lc;
        if (lc == 1) {
            int x; cout << " nhap gia tri can chen:"; cin >> x;
            chendau(heap, x);
        }
        else if (lc == 2) {
            int x; cout << " mhap gia tri can chen:"; cin >> x;
            chencuoi(heap, x);

        }
        else if (lc == 3) {
            int x, pos;; cout << " nhap gia tri can chen: "; cin >> x;
            cout << " nhap vi tri can chen:"; cin >> pos;
            chengiua(heap, x, pos);
        }
        else if (lc == 4) {
            deletedau(heap);
        }
        else if (lc == 5) {
            deletecuoi(heap);

        }
        else if (lc == 6) {
            int pos; cout << " moi ban nhap vi tri can xoa:"; cin >> pos;
            deletemidd(heap, pos);
        }
        else if (lc == 7) {
            in(heap);
        }
        else {
            cout << " lua chon khong hop le!\n";
        }
    }
    return 0;
}