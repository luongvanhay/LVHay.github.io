#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool LaSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đọc file, tìm số nguyên tố và ghi ra file kết quả
void XuLyFile(const char *inputFile, const char *outputFile) {
    ifstream fileIn(inputFile);
    ofstream fileOut(outputFile);

    if (!fileIn || !fileOut) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    int n;
    fileIn >> n; // Đọc số lượng phần tử

    vector<int> primeNumbers; // Danh sách chứa số nguyên tố

    for (int i = 0; i < n; i++) {
        int num;
        fileIn >> num;
        if (LaSoNguyenTo(num)) {
            primeNumbers.push_back(num);
        }
    }

    fileIn.close(); // Đóng file input

    // Sắp xếp danh sách số nguyên tố tăng dần
    sort(primeNumbers.begin(), primeNumbers.end());

    // Ghi kết quả ra file output
    fileOut << primeNumbers.size() << endl;
    for (int num : primeNumbers) {
        fileOut << num << " ";
    }

    fileOut.close(); // Đóng file output
}

int main() {
    XuLyFile("NT.INP", "NT.OUT");
    cout << "Xu ly xong, vui long kiem tra NT.OUT" << endl;
    return 0;
}
