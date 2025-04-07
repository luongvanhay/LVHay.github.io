#include <iostream>
using namespace std;

#define MAX 100 // Số lượng phần tử tối đa của dãy

void NhapMang(int *&a, int &n) {
    cout << "Mời bạn nhập số lượng phần tử: ";
    cin >> n;
    while (n <= 0 || n > MAX) {
        cout << "Nhập sai! Nhập lại: ";
        cin >> n;
    }
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Phần tử " << i << ": ";
        cin >> a[i];
    }
}

void XuatMang(int *a, int n) {
    cout << "Dãy số có " << n << " phần tử: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int DemChan(int *a, int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) dem++;
    }
    return dem;
}

void TachChan(int *a, int n, int *&b, int &m) {
    m = DemChan(a, n);
    b = new int[m];
    int cs = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            b[cs++] = a[i];
        }
    }
}

int main() {
    int *b = nullptr, k = 0;
    int *aChan = nullptr, nChan;
    
    NhapMang(b, k);
    TachChan(b, k, aChan, nChan);
    
    cout << "+ Dãy chứa các số chẵn\n";
    XuatMang(aChan, nChan);
    
    delete[] b;
    delete[] aChan;
    
    return 0;
}
