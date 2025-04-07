#include <iostream>
using namespace std;

/*
Hoán vị hai số nguyên dương
+ Vào: &a, &b
+ Ra: *a, *b
*/
void HoanVi(int *a, int *b) {
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}

int main() {
    /* Khai báo biến */
    int x, y;
    
    /* Nhập dữ liệu */
    cout << "Mời bạn nhập số a: ";
    cin >> x;
    cout << "Mời bạn nhập số b: ";
    cin >> y;
    
    /* Xử lý */
    cout << "Trước khi hoán vị, a = " << x << " và b = " << y << "." << endl;
    HoanVi(&x, &y);
    cout << "Sau khi hoán vị, a = " << x << " và b = " << y << "." << endl;
    
    return 0;
}
