#include <iostream>
#include <stack>
using namespace std;

// Tính số Fibonacci không dùng đệ quy
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    stack<int> s;
    s.push(0);
    s.push(1);
    for (int i = 2; i <= n; i++) {
        int a = s.top(); s.pop();
        int b = s.top();
        s.push(a);
        s.push(a + b);
    }
    return s.top();
}

// Đảo ngược số bằng stack
int daoNguocSo(int n) {
    stack<int> s;
    while (n > 0) {
        s.push(n % 10);
        n /= 10;
    }
    int ketQua = 0, heSo = 1;
    while (!s.empty()) {
        ketQua += s.top() * heSo;
        s.pop();
        heSo *= 10;
    }
    return ketQua;
}

// Giải bài toán Tháp Hà Nội bằng stack
struct DiChuyen {
    int dia, tu, den, trungGian;
};

void thapHaNoi(int n, int tu, int den, int trungGian) {
    stack<DiChuyen> s;
    s.push({ n, tu, den, trungGian });
    while (!s.empty()) {
        DiChuyen d = s.top(); s.pop();
        if (d.dia == 1) {
            cout << "Di chuyen dia " << d.dia << " tu " << d.tu << " den " << d.den << endl;
        }
        else {
            s.push({ d.dia - 1, d.trungGian, d.den, d.tu });
            s.push({ 1, d.tu, d.den, d.trungGian });
            s.push({ d.dia - 1, d.tu, d.trungGian, d.den });
        }
    }
}

int main() {
    // Test Fibonacci
    cout << "Fibonacci(10): " << fibonacci(10) << endl;

    // Test đảo ngược số
    cout << "Dao nguoc so 12345: " << daoNguocSo(12345) << endl;

    // Test Tháp Hà Nội
    cout << "Giai bai toan Thap Ha Noi voi 3 dia:" << endl;
    thapHaNoi(3, 1, 3, 2);

    return 0;
}
