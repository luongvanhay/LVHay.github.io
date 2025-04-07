#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

// Hàm tìm cặp số có tổng bằng k và ghi ra file
void TimCapSo(const char *inputFile, const char *outputFile) {
    ifstream fileIn(inputFile);
    ofstream fileOut(outputFile);

    if (!fileIn || !fileOut) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    int n, k;
    fileIn >> n >> k; // Đọc n và k

    vector<int> arr(n);
    unordered_set<int> seen;
    vector<pair<int, int>> pairs; // Lưu các cặp số hợp lệ

    for (int i = 0; i < n; i++) {
        fileIn >> arr[i]; // Đọc số từ file
    }
    fileIn.close();

    // Duyệt mảng để tìm cặp số
    for (int i = 0; i < n; i++) {
        int complement = k - arr[i];
        if (seen.find(complement) != seen.end()) {
            pairs.push_back({complement, arr[i]});
        }
        seen.insert(arr[i]); // Lưu vào tập hợp để kiểm tra nhanh
    }

    // Ghi kết quả ra file
    if (pairs.empty()) {
        fileOut << "0" << endl;
    } else {
        for (auto p : pairs) {
            fileOut << p.first << " " << p.second << endl;
        }
    }
    
    fileOut.close();
}

int main() {
    TimCapSo("CapSo.INP", "CapSo.OUT");
    cout << "Xu ly xong, vui long kiem tra CapSo.OUT" << endl;
    return 0;
}
