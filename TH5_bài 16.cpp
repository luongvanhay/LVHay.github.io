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

// Hàm tìm giá trị nhỏ nhất trong cây (dùng khi cần xóa)
Nut* timGiaTriNhoNhat(Nut* goc) {
    while (goc->trai != nullptr) {
        goc = goc->trai;
    }
    return goc;
}

// Hàm xóa một nút trong cây
Nut* xoaNut(Nut* goc, int giaTri) {
    if (goc == nullptr) {
        return goc; // Cây rỗng
    }

    // Đi tìm nút cần xóa
    if (giaTri < goc->giaTri) {
        goc->trai = xoaNut(goc->trai, giaTri);
    }
    else if (giaTri > goc->giaTri) {
        goc->phai = xoaNut(goc->phai, giaTri);
    }
    else {
        // Đã tìm thấy nút cần xóa
        if (goc->trai == nullptr) {
            Nut* temp = goc->phai;
            delete goc;
            return temp;
        }
        else if (goc->phai == nullptr) {
            Nut* temp = goc->trai;
            delete goc;
            return temp;
        }

        // Nút có hai nhánh con
        Nut* temp = timGiaTriNhoNhat(goc->phai); // Tìm giá trị nhỏ nhất trong cây con phải
        goc->giaTri = temp->giaTri; // Thay giá trị của nút cần xóa bằng giá trị tìm được
        goc->phai = xoaNut(goc->phai, temp->giaTri); // Xóa nút nhỏ nhất trong cây con phải
    }
    return goc;
}

// Hàm duyệt cây theo thứ tự NLR (Duyệt để kiểm tra)
void duyetNLR(Nut* goc) {
    if (goc == nullptr) return;
    cout << goc->giaTri << " ";
    duyetNLR(goc->trai);
    duyetNLR(goc->phai);
}

// Hàm main để kiểm tra chương trình
int main() {
    Nut* goc = nullptr;

    // Thêm các giá trị vào cây
    int giaTriNut[] = { 50, 30, 70, 20, 40, 60, 80 };
    int kichThuoc = sizeof(giaTriNut) / sizeof(giaTriNut[0]);

    for (int i = 0; i < kichThuoc; i++) {
        goc = themNut(goc, giaTriNut[i]);
    }

    cout << "Cay ban dau (NLR): ";
    duyetNLR(goc);
    cout << endl;

    // Xóa một vài giá trị
    goc = xoaNut(goc, 20); // Xóa lá
    goc = xoaNut(goc, 30); // Xóa nút có một nhánh con
    goc = xoaNut(goc, 50); // Xóa nút gốc

    cout << "Cay sau khi xoa (NLR): ";
    duyetNLR(goc);
    cout << endl;

    return 0;
}