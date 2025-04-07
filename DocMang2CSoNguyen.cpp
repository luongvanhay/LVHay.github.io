#include <iostream>
#include <fstream>

using namespace std;

void DocFileVaXuat(const char *filename) {
    ifstream file(filename); // Mở file để đọc
    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    int n, m;
    file >> n >> m; // Đọc số dòng và số cột

    int arr[n][m]; // Mảng chứa dữ liệu từ file

    // Đọc dữ liệu từ file vào mảng
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file >> arr[i][j];
        }
    }

    file.close(); // Đóng file

    // Xuất mảng ra màn hình
    cout << "Ma tran " << n << "x" << m << " doc tu file:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    DocFileVaXuat("MangSo.inp"); // Gọi hàm đọc file và xuất dữ liệu
    return 0;
}
