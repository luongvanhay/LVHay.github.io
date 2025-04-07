#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Ngăn xếp sử dụng mảng
class NganXepMang {
private:
    int dinh;
    int mang[100];
public:
    NganXepMang() { dinh = -1; }
    bool rong() { return dinh == -1; }
    bool day() { return dinh == 99; }
    void them(int x) {
        if (!day()) mang[++dinh] = x;
    }
    int xoa() {
        if (!rong()) return mang[dinh--];
        return -1;
    }
    int dinhNganXep() { return rong() ? -1 : mang[dinh]; }
};

// Ngăn xếp sử dụng danh sách liên kết
class NganXepLienKet {
private:
    struct Nut {
        int duLieu;
        Nut* keTiep;
    };
    Nut* dinh;
public:
    NganXepLienKet() { dinh = nullptr; }
    bool rong() { return dinh == nullptr; }
    void them(int x) {
        Nut* nutMoi = new Nut{ x, dinh };
        dinh = nutMoi;
    }
    int xoa() {
        if (rong()) return -1;
        int duLieu = dinh->duLieu;
        Nut* tam = dinh;
        dinh = dinh->keTiep;
        delete tam;
        return duLieu;
    }
    int dinhNganXep() { return rong() ? -1 : dinh->duLieu; }
};

// Đảo số sử dụng ngăn xếp
void daoSo(int so) {
    stack<int> s;
    while (so > 0) {
        s.push(so % 10);
        so /= 10;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

// Kiểm tra chuỗi đối xứng
bool doiXung(string chuoi) {
    stack<char> s;
    for (char c : chuoi) s.push(c);
    for (char c : chuoi) {
        if (c != s.top()) return false;
        s.pop();
    }
    return true;
}

// Chuyển đổi số thập phân sang nhị phân
void thapPhanSangNhiPhan(int so) {
    stack<int> s;
    while (so > 0) {
        s.push(so % 2);
        so /= 2;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

// Chuyển biểu thức trung tố sang hậu tố
int uuTien(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

string trungToSangHauTo(string bieuThuc) {
    stack<char> s;
    string ketQua;
    for (char c : bieuThuc) {
        if (isdigit(c)) ketQua += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                ketQua += s.top(); s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && uuTien(s.top()) >= uuTien(c)) {
                ketQua += s.top(); s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        ketQua += s.top(); s.pop();
    }
    return ketQua;
}

// Tính giá trị biểu thức hậu tố
int tinhGiaTriHauTo(string bieuThuc) {
    stack<int> s;
    for (char c : bieuThuc) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (c) {
            case '+': s.push(a + b); break;
            case '-': s.push(a - b); break;
            case '*': s.push(a * b); break;
            case '/': s.push(a / b); break;
            }
        }
    }
    return s.top();
}

int main() {
    // Test đảo số
    cout << "Dao so 12345: ";
    daoSo(12345);

    // Test kiểm tra chuỗi đối xứng
    cout << "Chuoi 'madam' doi xung? " << (doiXung("madam") ? "Co" : "Khong") << endl;

    // Test chuyển số thập phân sang nhị phân
    cout << "Nhi phan cua 10: ";
    thapPhanSangNhiPhan(10);

    // Test chuyển trung tố sang hậu tố và tính toán
    string trungTo = "3+5*2";
    string hauTo = trungToSangHauTo(trungTo);
    cout << "Hau to cua " << trungTo << ": " << hauTo << endl;
    cout << "Gia tri bieu thuc: " << tinhGiaTriHauTo(hauTo) << endl;

    return 0;
}
