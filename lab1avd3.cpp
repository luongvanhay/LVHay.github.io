#include <iostream>
#include <cstdlib>

int main() {
    /* Con trỏ với mảng tĩnh */
    int a[5] = {2, 4, 5, 8}; // Mảng tĩnh
    int na = 3; // Số phần tử của mảng
    int *p = nullptr; // con trỏ rỗng
    p = a + 1; // trỏ tới phần tử thứ 1

    // Địa chỉ, giá trị, giá trị tham chiếu
    std::cout << "p: Addr=" << &p << ", Val=" << p << ", ValRef=" << *p << std::endl;
    p = p + 1; // di chuyển qua bên phải 1 đơn vị
    int x = p[-2]; // *(p - 2) - di chuyển qua trái 2 đơn vị

    /* Con trỏ với mảng động */
    int *b = nullptr; // Khai báo mảng rỗng
    int nb = 3;
    b = new int[nb]; // Cấp phát nb phần tử (C++)
    
    b[0] = 10;
    b[1] = 20;
    b[2] = 30;

    // In giá trị của mảng động
    std::cout << "Mảng động:" << std::endl;
    for (int i = 0; i < nb; i++) {
        std::cout << "b[" << i << "]: Addr=" << (b + i) << ", Val=" << b[i] << std::endl;
    }

    // Hủy vùng nhớ cấp phát
    delete[] b;
    return 0;
}
