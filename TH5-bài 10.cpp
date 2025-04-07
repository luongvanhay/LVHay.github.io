#include <iostream>
#include <fstream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Nut {
    float giaTri;
    Nut* trai;
    Nut* phai;
    Nut(float x) : giaTri(x), trai(nullptr), phai(nullptr) {}
};

// Hàm thêm nút vào cây nhị phân tìm kiếm
Nut* themNut(Nut* goc, float giaTri) {
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

// Hàm duyệt cây theo thứ tự LRN và ghi giá trị vào tập tin nhị phân
void duyetLRN(Nut* goc, ofstream& file) {
    if (goc == nullptr) return;

    // Duyệt cây con bên trái
    duyetLRN(goc->trai, file);

    // Duyệt cây con bên phải
    duyetLRN(goc->phai, file);

    // Ghi giá trị của nút hiện tại vào tập tin
    file.write((char*)&goc->giaTri, sizeof(float));
}

// Hàm main để kiểm tra chương trình
int main() {
    Nut* goc = nullptr;

    // Thêm các giá trị vào cây
    float giaTriNut[] = { 5.5, 2.2, 8.8, 1.1, 3.3, 7.7, 9.9 };
    int kichThuoc = sizeof(giaTriNut) / sizeof(giaTriNut[0]);

    for (int i = 0; i < kichThuoc; i++) {
        goc = themNut(goc, giaTriNut[i]);
    }

    // Mở tập tin nhị phân để ghi dữ liệu
    ofstream file("data.out", ios::binary);
    if (!file) {
        cerr << "Khong the mo tap tin de ghi!" << endl;
        return 1;
    }

    // Duyệt cây và ghi dữ liệu vào tập tin
    duyetLRN(goc, file);

    cout << "Cay da duoc duyet theo phuong phap LRN va ghi vao tap tin data.out." << endl;

    // Đóng tập tin
    file.close();

    return 0;
}