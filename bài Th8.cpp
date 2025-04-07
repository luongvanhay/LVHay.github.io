#include <iostream>
using namespace std;

struct Nut {
    int khoa, chieuCao;
    Nut* trai;
    Nut* phai;
    Nut(int k) : khoa(k), chieuCao(1), trai(nullptr), phai(nullptr) {}
};

int layChieuCao(Nut* nut) {
    return nut ? nut->chieuCao : 0;
}

int layCanBang(Nut* nut) {
    return nut ? layChieuCao(nut->trai) - layChieuCao(nut->phai) : 0;
}

Nut* xoayPhai(Nut* y) {
    Nut* x = y->trai;
    Nut* T2 = x->phai;
    x->phai = y;
    y->trai = T2;
    y->chieuCao = max(layChieuCao(y->trai), layChieuCao(y->phai)) + 1;
    x->chieuCao = max(layChieuCao(x->trai), layChieuCao(x->phai)) + 1;
    return x;
}

Nut* xoayTrai(Nut* x) {
    Nut* y = x->phai;
    Nut* T2 = y->trai;
    y->trai = x;
    x->phai = T2;
    x->chieuCao = max(layChieuCao(x->trai), layChieuCao(x->phai)) + 1;
    y->chieuCao = max(layChieuCao(y->trai), layChieuCao(y->phai)) + 1;
    return y;
}

Nut* chen(Nut* nut, int khoa) {
    if (!nut) return new Nut(khoa);
    if (khoa < nut->khoa)
        nut->trai = chen(nut->trai, khoa);
    else if (khoa > nut->khoa)
        nut->phai = chen(nut->phai, khoa);
    else
        return nut;
    nut->chieuCao = max(layChieuCao(nut->trai), layChieuCao(nut->phai)) + 1;
    int canBang = layCanBang(nut);
    if (canBang > 1 && khoa < nut->trai->khoa)
        return xoayPhai(nut);
    if (canBang < -1 && khoa > nut->phai->khoa)
        return xoayTrai(nut);
    if (canBang > 1 && khoa > nut->trai->khoa) {
        nut->trai = xoayTrai(nut->trai);
        return xoayPhai(nut);
    }
    if (canBang < -1 && khoa < nut->phai->khoa) {
        nut->phai = xoayPhai(nut->phai);
        return xoayTrai(nut);
    }
    return nut;
}

Nut* nutNhoNhat(Nut* nut) {
    Nut* hienTai = nut;
    while (hienTai->trai)
        hienTai = hienTai->trai;
    return hienTai;
}

Nut* xoa(Nut* goc, int khoa) {
    if (!goc) return goc;
    if (khoa < goc->khoa)
        goc->trai = xoa(goc->trai, khoa);
    else if (khoa > goc->khoa)
        goc->phai = xoa(goc->phai, khoa);
    else {
        if (!goc->trai || !goc->phai) {
            Nut* tam = goc->trai ? goc->trai : goc->phai;
            if (!tam) {
                tam = goc;
                goc = nullptr;
            }
            else
                *goc = *tam;
            delete tam;
        }
        else {
            Nut* tam = nutNhoNhat(goc->phai);
            goc->khoa = tam->khoa;
            goc->phai = xoa(goc->phai, tam->khoa);
        }
    }
    if (!goc) return goc;
    goc->chieuCao = max(layChieuCao(goc->trai), layChieuCao(goc->phai)) + 1;
    int canBang = layCanBang(goc);
    if (canBang > 1 && layCanBang(goc->trai) >= 0)
        return xoayPhai(goc);
    if (canBang > 1 && layCanBang(goc->trai) < 0) {
        goc->trai = xoayTrai(goc->trai);
        return xoayPhai(goc);
    }
    if (canBang < -1 && layCanBang(goc->phai) <= 0)
        return xoayTrai(goc);
    if (canBang < -1 && layCanBang(goc->phai) > 0) {
        goc->phai = xoayPhai(goc->phai);
        return xoayTrai(goc);
    }
    return goc;
}

void duyetLNR(Nut* goc) {
    if (goc) {
        duyetLNR(goc->trai);
        cout << goc->khoa << " ";
        duyetLNR(goc->phai);
    }
}

int main() {
    Nut* goc = nullptr;
    goc = chen(goc, 10);
    goc = chen(goc, 20);
    goc = chen(goc, 30);
    goc = chen(goc, 40);
    goc = chen(goc, 50);
    goc = chen(goc, 25);
    cout << "Duyet LNR: ";
    duyetLNR(goc);
    cout << endl;
    goc = xoa(goc, 30);
    cout << "Duyet LNR sau khi xoa: ";
    duyetLNR(goc);
    cout << endl;
    return 0;
}
