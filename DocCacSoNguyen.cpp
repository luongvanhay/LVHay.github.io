#include <iostream>
#include <fstream>

using namespace std;

void DocFileVaXuat(const char *filename) {
    ifstream file(filename); // Mở file để đọc
    if (!file) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    int n;
    file >> n; // Đọc số phần tử

    int arr[n]; // Mảng chứa các số nguyên
    for (int i = 0; i < n; i++) {
        file >> arr[i]; // Đọc từng số vào mảng
    }

    file.close(); // Đóng file

    // Xuất mảng ra màn hình
    cout << "So phan tu: " << n << endl;
    cout << "Cac so trong file: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    DocFileVaXuat("DaySoNguyen.inp"); // Gọi hàm đọc file và xuất dữ liệu
    return 0;
}
