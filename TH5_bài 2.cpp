#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct Nut {
    int giaTri;
    Nut* trai;
    Nut* phai;
    Nut(int x) : giaTri(x), trai(nullptr), phai(nullptr) {}
};

// Hàm chuyển đổi cây từ Hình 1 sang Hình 2
void chuyenDoi(Nut* goc) {
    if (!goc || !goc->phai || !goc->phai->trai) return;

    Nut* tam = goc->phai->trai; // Lưu nút con bên trái của goc->phai
    goc->phai->trai = nullptr; // Ngắt liên kết
    tam->phai = goc->phai;     // Gán goc->phai làm con phải của tam
    goc->phai = tam;           // Gán tam làm con phải mới của gốc
}

// Hàm main để kiểm tra chương trình
int main() {
    // Tạo cây Hình 1
    Nut* goc = new Nut(1);
    goc->trai = new Nut(2);
    goc->phai = new Nut(3);
    goc->phai->trai = new Nut(4);
    goc->phai->phai = new Nut(5);

    // Chuyển đổi cây
    chuyenDoi(goc);

    // Kiểm tra kết quả sau chuyển đổi (Hình 2)
    cout << "Nut goc: " << goc->giaTri << endl;
    cout << "Con trai: " << goc->trai->giaTri << endl;
    cout << "Con phai: " << goc->phai->giaTri << endl;
    cout << "Con phai cua nut phai: " << goc->phai->phai->giaTri << endl;

    return 0;
}