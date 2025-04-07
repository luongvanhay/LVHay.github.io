#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct MatHang {
    string maMH;
    string tenMH;
    int soLuong;
    int donGia;
};

class QuanLyMatHang {
private:
    vector<MatHang> danhSach;
    const int MAX_SIZE = 100;

public:
    // Kiểm tra mặt hàng đã tồn tại chưa
    int TimKiem(string ten) {
        for (int i = 0; i < danhSach.size(); i++) {
            if (danhSach[i].tenMH == ten)
                return i;
        }
        return -1;
    }

    // Thêm mặt hàng vào danh sách
    void ThemMatHang() {
        if (danhSach.size() >= MAX_SIZE) {
            cout << "Danh sách đã đầy!\n";
            return;
        }
        MatHang mh;
        cout << "Nhập mã mặt hàng: "; cin >> mh.maMH;
        cin.ignore();
        cout << "Nhập tên mặt hàng: "; getline(cin, mh.tenMH);
        cout << "Nhập số lượng: "; cin >> mh.soLuong;
        cout << "Nhập đơn giá: "; cin >> mh.donGia;
        danhSach.push_back(mh);
        cout << "Thêm mặt hàng thành công!\n";
    }

    // Tìm và hiển thị thông tin mặt hàng theo tên
    void TimMatHang() {
        string ten;
        cout << "Nhập tên mặt hàng cần tìm: "; cin.ignore(); getline(cin, ten);
        int idx = TimKiem(ten);
        if (idx == -1) {
            cout << "Không có mặt hàng đang tìm!\n";
        } else {
            cout << "Mã: " << danhSach[idx].maMH << ", Số lượng: " << danhSach[idx].soLuong << ", Đơn giá: " << danhSach[idx].donGia << "\n";
        }
    }

    // Tính tổng số lượng các mặt hàng
    void TongSoLuong() {
        int tong = 0;
        for (const auto &mh : danhSach) {
            tong += mh.soLuong;
        }
        cout << "Tổng số lượng các mặt hàng: " << tong << "\n";
    }

    // Xuất danh sách mặt hàng
    void XuatDanhSach() {
        if (danhSach.empty()) {
            cout << "Danh sách rỗng!\n";
            return;
        }
        cout << "Danh sách mặt hàng:\n";
        for (const auto &mh : danhSach) {
            cout << "Mã: " << mh.maMH << ", Tên: " << mh.tenMH << ", Số lượng: " << mh.soLuong << ", Đơn giá: " << mh.donGia << "\n";
        }
    }
};

int main() {
    QuanLyMatHang ql;
    int luaChon;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Thêm mặt hàng\n";
        cout << "2. Tìm mặt hàng theo tên\n";
        cout << "3. Tính tổng số lượng mặt hàng\n";
        cout << "4. Xuất danh sách mặt hàng\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn: "; cin >> luaChon;
        switch (luaChon) {
            case 1: ql.ThemMatHang(); break;
            case 2: ql.TimMatHang(); break;
            case 3: ql.TongSoLuong(); break;
            case 4: ql.XuatDanhSach(); break;
            case 0: cout << "Thoát chương trình!\n"; break;
            default: cout << "Lựa chọn không hợp lệ!\n";
        }
    } while (luaChon != 0);
    return 0;
}
