#include <iostream>
#include <cstring>

using namespace std;

void XoaKyTuTaiViTri(char *s, int k) {
    int len = strlen(s);

    if (k < 0 || k >= len) {
        cout << "Vi tri k khong hop le!" << endl;
        return;
    }

    // Dịch chuyển các ký tự sang trái từ vị trí k
    for (int i = k; i < len - 1; i++) {
        s[i] = s[i + 1];
    }
    s[len - 1] = '\0'; // Kết thúc chuỗi
}

int main() {
    char s[1001];
    int k;

    cout << "Nhap chuoi: ";
    cin.getline(s, 1001);

    cout << "Nhap vi tri k can xoa (0-based index): ";
    cin >> k;

    XoaKyTuTaiViTri(s, k);

    cout << "Chuoi sau khi xoa: " << s << endl;

    return 0;
}
