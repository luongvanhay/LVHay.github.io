#include <iostream>
#include <cstring>

using namespace std;

int DemSoTu(const char *s) {
    int count = 0;
    bool inWord = false; // Biến kiểm tra có đang ở trong một từ không

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') { // Ký tự không phải khoảng trắng
            if (!inWord) {
                count++; // Bắt đầu một từ mới
                inWord = true;
            }
        } else {
            inWord = false; // Kết thúc một từ
        }
    }

    return count;
}

int main() {
    char s[1001];
    cout << "Nhap chuoi: ";
    cin.getline(s, 1001);

    int soTu = DemSoTu(s);
    cout << "So tu trong chuoi: " << soTu << endl;

    return 0;
}
