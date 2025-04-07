// Bài 2: Hàng đợi số nguyên
#include <iostream>
#include <queue>
using namespace std;

// Hàng đợi sử dụng mảng
class HangDoiMang {
private:
    int dau, cuoi;
    int mang[100];
public:
    HangDoiMang() { dau = cuoi = -1; }
    bool rong() { return dau == -1; }
    bool day() { return cuoi == 99; }
    void them(int x) {
        if (day()) return;
        if (rong()) dau = 0;
        mang[++cuoi] = x;
    }
    int xoa() {
        if (rong()) return -1;
        int giaTri = mang[dau];
        if (dau == cuoi) dau = cuoi = -1;
        else dau++;
        return giaTri;
    }
    int truoc() { return rong() ? -1 : mang[dau]; }
};

// Hàng đợi sử dụng danh sách liên kết
class HangDoiLienKet {
private:
    struct Nut {
        int duLieu;
        Nut* keTiep;
    };
    Nut* dau, * cuoi;
public:
    HangDoiLienKet() { dau = cuoi = nullptr; }
    bool rong() { return dau == nullptr; }
    void them(int x) {
        Nut* nutMoi = new Nut{ x, nullptr };
        if (rong()) dau = cuoi = nutMoi;
        else {
            cuoi->keTiep = nutMoi;
            cuoi = nutMoi;
        }
    }
    int xoa() {
        if (rong()) return -1;
        int giaTri = dau->duLieu;
        Nut* tam = dau;
        dau = dau->keTiep;
        delete tam;
        if (dau == nullptr) cuoi = nullptr;
        return giaTri;
    }
    int truoc() { return rong() ? -1 : dau->duLieu; }
};

int main() {
    HangDoiMang hdm;
    hdm.them(1);
    hdm.them(2);
    hdm.them(3);
    cout << "Hang doi mang: " << hdm.xoa() << " " << hdm.xoa() << endl;

    HangDoiLienKet hdlk;
    hdlk.them(10);
    hdlk.them(20);
    hdlk.them(30);
    cout << "Hang doi lien ket: " << hdlk.xoa() << " " << hdlk.xoa() << endl;

    return 0;
}
