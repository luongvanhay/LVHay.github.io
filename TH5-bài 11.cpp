#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
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

// Hàm duyệt cây theo trung thứ tự (LNR)
void duyetLNR(Nut* goc) {
    if (goc == nullptr) return;

    duyetLNR(goc->trai);     // Duyệt cây con trái
    cout << goc->giaTri << " "; // In giá trị nút gốc
    duyetLNR(goc->phai);     // Duyệt cây con phải
}

// Hàm main để kiểm tra chương trình
int main() {
    Nut* goc = nullptr;

    // Thêm các giá trị vào cây
    int thuTuThem[] = { 10, 5, 15, 3, 9, 7, 12, 18, 20 };
    int kichThuoc = sizeof(thuTuThem) / sizeof(thuTuThem[0]);

    for (int i = 0; i < kichThuoc; i++) {
        goc = themNut(goc, thuTuThem[i]);
    }

    // In các giá trị theo thứ tự tăng dần
    cout << "Cac gia tri theo thu tu tang dan: ";
    duyetLNR(goc);
    cout << endl;

    return 0;
}