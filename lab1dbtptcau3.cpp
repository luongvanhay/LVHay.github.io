#include <iostream>
#include <cstring>

using namespace std;

void ChenKyTuTaiViTri(char *s, int &len, int k, char c) {
    if (k < 0 || k > len) {
        cout << "Vi tri k khong hop le!" << endl;
        return;
    }

    // Dịch chuyển các ký tự sang phải từ vị trí k
    for (int i = len; i > k; i--) {
        s[i] = s[i - 1];
    }

    s[k] = c;   // Chèn ký tự c vào vị trí k
    s[len + 1] = '\0'; // Kết thúc chuỗi
    len++; // Tăng độ dài chuỗi
}

int main() {
    char s[1002]; // Kích thước lớn hơn để chứa ký tự chèn thêm
    int k;
    char c;

    cout << "Nhap chuoi: ";
    cin.getline(s, 1001);

    cout << "Nhap vi tri k can chen (0-based index): ";
    cin >> k;

    cout << "Nhap ky tu can chen: ";
    cin >> c;

    int len = strlen(s);
    ChenKyTuTaiViTri(s, len, k, c);

    cout << "Chuoi sau khi chen: " << s << endl;

    return 0;
}
