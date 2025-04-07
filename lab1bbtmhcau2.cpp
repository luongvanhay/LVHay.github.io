#include <iostream>
#include <cmath>
using namespace std;

/*
Kiểm tra số chính phương
+ Vào: *n
+ Ra: true nếu là số chính phương, false nếu không
*/
bool LaSoChinhPhuong(int *n) {
    int canBacHai = sqrt(*n);
    return (canBacHai * canBacHai == *n);
}

int main() {
    /* Khai báo biến */
    int n;
    
    /* Nhập dữ liệu */
    cout << "Mời bạn nhập số nguyên dương n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Vui lòng nhập số nguyên dương!" << endl;
        return 1;
    }
    
    /* Xử lý và xuất kết quả */
    if (LaSoChinhPhuong(&n)) {
        cout << n << " là số chính phương." << endl;
    } else {
        cout << n << " không phải là số chính phương." << endl;
    }
    
    return 0;
}
