#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct Nut {
    int giaTri;
    Nut* trai;
    Nut* phai;
    Nut(int x) : giaTri(x), trai(nullptr), phai(nullptr) {}
};

// Hàm tính số nút trong cây nhị phân tìm kiếm
int tinhSoNut(Nut* goc) {
    if (goc == nullptr) return 0; // Nếu cây rỗng, số nút là 0
    return 1 + tinhSoNut(goc->trai) + tinhSoNut(goc->phai); // Số nút gốc + trái + phải
}

// Hàm tính tổng giá trị các nút trong cây nhị phân tìm kiếm
int tinhTongGiaTri(Nut* goc) {
    if (goc == nullptr) return 0; // Nếu cây rỗng, tổng giá trị là 0
    return goc->giaTri + tinhTongGiaTri(goc->trai) + tinhTongGiaTri(goc->phai); // Giá trị gốc + trái + phải
}

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

// Hàm main để kiểm tra chương trình
int main() {
    Nut* goc = nullptr;

    // Thêm các nút vào cây
    int giaTriNut[] = { 10, 5, 15, 3, 7, 12, 18 };
    int kichThuoc = sizeof(giaTriNut) / sizeof(giaTriNut[0]);

    for (int i = 0; i < kichThuoc; i++) {
        goc = themNut(goc, giaTriNut[i]);
    }

    // Tính số nút trong cây
    cout << "So nut trong cay: " << tinhSoNut(goc) << endl;

    // Tính tổng giá trị các nút trong cây
    cout << "Tong gia tri cac nut: " << tinhTongGiaTri(goc) << endl;

    return 0;
}