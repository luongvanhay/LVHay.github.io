#include <iostream>
#include <fstream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
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

// Hàm ghi cây vào tập tin nhị phân theo thứ tự LNR (trung thứ tự)
void ghiCay(Nut* goc, ofstream& file) {
    if (goc == nullptr) {
        float dauCuoi = -1.0f; // Đánh dấu vị trí nullptr
        file.write((char*)&dauCuoi, sizeof(float));
        return;
    }

    // Ghi giá trị nút gốc
    file.write((char*)&goc->giaTri, sizeof(float));

    // Ghi cây con trái
    ghiCay(goc->trai, file);

    // Ghi cây con phải
    ghiCay(goc->phai, file);
}

// Hàm đọc cây từ tập tin nhị phân
Nut* docCay(ifstream& file) {
    float giaTri;
    if (!file.read((char*)&giaTri, sizeof(float)) || giaTri == -1.0f) {
        return nullptr;
    }

    Nut* goc = new Nut(giaTri);
    goc->trai = docCay(file); // Đọc cây con trái
    goc->phai = docCay(file); // Đọc cây con phải
    return goc;
}

// Hàm duyệt cây theo LNR (trung thứ tự) để kiểm tra
void duyetLNR(Nut* goc) {
    if (goc == nullptr) return;
    duyetLNR(goc->trai);
    cout << goc->giaTri << " ";
    duyetLNR(goc->phai);
}

// Hàm main để kiểm tra chương trình
int main() {
    Nut* goc = nullptr;

    // Thêm các giá trị vào cây
    float thuTuThem[] = { 5.5, 2.2, 8.8, 1.1, 3.3, 7.7, 9.9 };
    int kichThuoc = sizeof(thuTuThem) / sizeof(thuTuThem[0]);

    for (int i = 0; i < kichThuoc; i++) {
        goc = themNut(goc, thuTuThem[i]);
    }

    // Ghi cây xuống tập tin nhị phân
    ofstream fileOut("cay_nhiphan.bin", ios::binary);
    ghiCay(goc, fileOut);
    fileOut.close();
    cout << "Cay da duoc them vao tap tin." << endl;

    // Đọc lại cây từ tập tin nhị phân
    ifstream fileIn("cay_nhiphan.bin", ios::binary);
    Nut* cayDoc = docCay(fileIn);
    fileIn.close();

    // Hiển thị cây đã đọc được
    cout << "Cay sau khi doc tu tap tin (theo thu tu LNR): ";
    duyetLNR(cayDoc);
    cout << endl;

    return 0;
}