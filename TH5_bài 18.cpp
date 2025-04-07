#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct Nut {
    int giaTri;
    Nut* trai;
    Nut* phai;
    Nut(int x) : giaTri(x), trai(nullptr), phai(nullptr) {}
};

// Hàm thêm nút vào cây nhị phân tìm kiếm
Nut* themNut(Nut* goc, int giaTri) {
    if (goc == nullptr) {
        return new Nut(giaTri);
    }
    if (giaTri < goc->giaTri) {
        goc->trai = themNut(goc->trai, giaTri);
    }
    else {
        goc->phai = themNut(goc->phai, giaTri);
    }
    return goc;
}

// Hàm tạo cây từ mảng
Nut* taoCay(int a[], int n) {
    Nut* goc = nullptr;
    for (int i = 0; i < n; i++) {
        goc = themNut(goc, a[i]);
    }
    return goc;
}

// Hàm duyệt cây theo trung thứ tự (LNR) và đưa các giá trị vào mảng
void duyetLNR(Nut* goc, int a[], int& index) {
    if (goc == nullptr) return;
    duyetLNR(goc->trai, a, index);   // Duyệt cây con trái
    a[index++] = goc->giaTri;       // Lưu giá trị nút gốc vào mảng
    duyetLNR(goc->phai, a, index);  // Duyệt cây con phải
}

// Hàm main để kiểm tra chương trình
int main() {
    // Mảng đầu vào
    int a[] = { 10, 5, 15, 3, 7, 12, 18 };
    int n = sizeof(a) / sizeof(a[0]);

    // Tạo cây nhị phân tìm kiếm từ mảng
    Nut* goc = taoCay(a, n);

    // Duyệt cây và đưa các phần tử trở lại mảng
    int index = 0; // Biến index để theo dõi vị trí trong mảng
    duyetLNR(goc, a, index);

    // Hiển thị mảng đã sắp xếp
    cout << "Mang sau khi xap sep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}