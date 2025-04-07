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

// Hàm duyệt cây theo hậu thứ tự (Post-order traversal)
void duyetHauThuTu(Nut* goc) {
    if (goc == nullptr) return;
    duyetHauThuTu(goc->trai);
    duyetHauThuTu(goc->phai);
    cout << goc->giaTri << " ";
}

// Hàm main để kiểm tra chương trình
int main() {
    Nut* goc = nullptr;

    // Thêm các nút theo thứ tự
    int thuTuThem[] = { 5, 3, 10, 7, 9, 15, 12, 18, 20 };
    for (int i = 0; i < sizeof(thuTuThem) / sizeof(thuTuThem[0]); i++) {
        goc = themNut(goc, thuTuThem[i]);
    }

    // Duyệt cây theo hậu thứ tự
    cout << "Phep duyet hau thu tu: ";
    duyetHauThuTu(goc);
    cout << endl;

    return 0;
}