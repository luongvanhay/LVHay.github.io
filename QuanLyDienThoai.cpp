#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DienThoai {
    string maDT;
    string nhanHieu;
    int gia;
};

class QuanLyDienThoai {
private:
    vector<DienThoai> danhSach;
    const int MAX_SIZE = 100;

public:
    // Kiểm tra điện thoại đã tồn tại chưa
    int TimKiem(string ma) {
        for (int i = 0; i < danhSach.size(); i++) {
            if (danhSach[i].maDT == ma)
                return i;
        }
        return -1;
    }

    // Thêm điện thoại vào danh sách
    void ThemDienThoai() {
        if (danhSach.size() >= MAX_SIZE) {
            cout << "Danh sách đã đầy!\n";
            return;
        }
        DienThoai dt;
        cout << "Nhập mã điện thoại: "; cin >> dt.maDT;
        if (TimKiem(dt.maDT) != -1) {
            cout << "Mã điện thoại đã tồn tại!\n";
            return;
        }
        cin.ignore();
        cout << "Nhập nhãn hiệu: "; getline(cin, dt.nhanHieu);
        cout << "Nhập giá: "; cin >> dt.gia;
        danhSach.push_back(dt);
        cout << "Thêm điện thoại thành công!\n";
    }

    // Tìm và hiển thị thông tin điện thoại theo mã
    void TimDienThoai() {
        string ma;
        cout << "Nhập mã điện thoại cần tìm: "; cin >> ma;
        int idx = TimKiem(ma);
        if (idx == -1) {
            cout << "Không tìm thấy điện thoại!\n";
        } else {
            cout << "Nhãn hiệu: " << danhSach[idx].nhanHieu << ", Giá: " << danhSach[idx].gia << "\n";
        }
    }

    // Cập nhật giá điện thoại theo mã
    void CapNhatGia() {
        string ma;
        cout << "Nhập mã điện thoại cần cập nhật giá: "; cin >> ma;
        int idx = TimKiem(ma);
        if (idx == -1) {
            cout << "Không tìm thấy điện thoại!\n";
        } else {
            cout << "Nhập giá mới: "; cin >> danhSach[idx].gia;
            cout << "Cập nhật thành công!\n";
        }
    }

    // Xóa điện thoại theo mã
    void XoaDienThoai() {
        string ma;
        cout << "Nhập mã điện thoại cần xóa: "; cin >> ma;
        int idx = TimKiem(ma);
        if (idx == -1) {
            cout << "Không tìm thấy điện thoại!\n";
        } else {
            danhSach.erase(danhSach.begin() + idx);
            cout << "Xóa thành công!\n";
        }
    }

    // Xuất danh sách điện thoại
    void XuatDanhSach() {
        if (danhSach.empty()) {
            cout << "Danh sách rỗng!\n";
            return;
        }
        cout << "Danh sách điện thoại:\n";
        for (const auto &dt : danhSach) {
            cout << "Mã: " << dt.maDT << ", Nhãn hiệu: " << dt.nhanHieu << ", Giá: " << dt.gia << "\n";
        }
    }
};

int main() {
    QuanLyDienThoai ql;
    int luaChon;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Thêm điện thoại\n";
        cout << "2. Tìm điện thoại theo mã\n";
        cout << "3. Cập nhật giá điện thoại\n";
        cout << "4. Xóa điện thoại\n";
        cout << "5. Xuất danh sách điện thoại\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn: "; cin >> luaChon;
        switch (luaChon) {
            case 1: ql.ThemDienThoai(); break;
            case 2: ql.TimDienThoai(); break;
            case 3: ql.CapNhatGia(); break;
            case 4: ql.XoaDienThoai(); break;
            case 5: ql.XuatDanhSach(); break;
            case 0: cout << "Thoát chương trình!\n"; break;
            default: cout << "Lựa chọn không hợp lệ!\n";
        }
    } while (luaChon != 0);
    return 0;
}
