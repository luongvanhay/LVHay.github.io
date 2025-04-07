#include <iostream>
using namespace std;

#define MAX 100 // Số lượng phần tử tối đa của dãy

void NhapMang(int *&a, int &n) {
    cout << "Mời bạn nhập số lượng phần tử: ";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Phần tử " << i << ": ";
        cin >> a[i];
    }
}

void NhapMang(int **a, int *n) {
    cout << "Mời bạn nhập số lượng phần tử: ";
    cin >> *n;
    *a = new int[*n];
    for (int i = 0; i < *n; i++) {
        cout << "Phần tử " << i << ": ";
        cin >> (*a)[i];
    }
}

void XuatMang(int *a, int n) {
    cout << "Dãy số có " << n << " phần tử: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void DoiChan(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            a[i] = 0;
        }
    }
}

int main() {
    int *b = NULL, k = 0;
    
    NhapMang(&b, &k);
    XuatMang(b, k);
    
    DoiChan(b, k);
    cout << "* Đổi giá trị chẵn thành số 0: " << endl;
    XuatMang(b, k);
    
    if (b != NULL) delete[] b;
    
    return 0;
}