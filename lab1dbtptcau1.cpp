#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void SapXepChuoi(char *s) {
    int len = strlen(s);
    sort(s, s + len); // Sắp xếp chuỗi theo thứ tự tăng dần
}

int main() {
    char s[1001];
    cout << "Nhap chuoi: ";
    cin.getline(s, 1001);

    SapXepChuoi(s);

    cout << "Chuoi sau khi sap xep: " << s << endl;

    return 0;
}
