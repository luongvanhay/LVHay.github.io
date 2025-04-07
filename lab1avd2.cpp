#include <iostream>

// [1] Truyền tham trị
void HoanVi_ByValue(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// [2] Truyền tham biến
void HoanVi_ByReference(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// [3] Truyền tham chiếu
void HoanVi_ByPointer(int *a, int *b) {
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}

int main() {
    int x = 5, y = 10;
    std::cout << "[1] Truyền tham trị:" << std::endl;
    std::cout << "Trước: x=" << x << ", y=" << y << std::endl;
    HoanVi_ByValue(x, y);
    std::cout << "Sau: x=" << x << ", y=" << y << " (Không thay đổi)" << std::endl;

    x = 5, y = 10;
    std::cout << "\n[2] Truyền tham biến:" << std::endl;
    std::cout << "Trước: x=" << x << ", y=" << y << std::endl;
    HoanVi_ByReference(x, y);
    std::cout << "Sau: x=" << x << ", y=" << y << " (Đã hoán đổi)" << std::endl;

    x = 5, y = 10;
    std::cout << "\n[3] Truyền tham chiếu:" << std::endl;
    std::cout << "Trước: x=" << x << ", y=" << y << std::endl;
    HoanVi_ByPointer(&x, &y);
    std::cout << "Sau: x=" << x << ", y=" << y << " (Đã hoán đổi)" << std::endl;

    // [4] Biến tham chiếu
    int* y_ptr = &x;
    std::cout << "\n[4] Biến tham chiếu:" << std::endl;
    std::cout << "x: Addr=" << &x << ", Val=" << x << std::endl;
    std::cout << "y_ptr: Addr=" << &y_ptr << ", Val=" << y_ptr << " (giá trị tại y_ptr: " << *y_ptr << ")" << std::endl;
    
    return 0;
}
