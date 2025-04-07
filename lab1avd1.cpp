#include <iostream>
#include <cstdlib>

int main() {
    /* Con trỏ tham chiếu tới đối tượng tĩnh */
    int n; // biến số nguyên n

    // biến con trỏ chứa địa chỉ tham chiếu tới vùng nhớ chứa số nguyên
    int *p = nullptr; // con trỏ không sử dụng phải gán nullptr
    n = 20;
    p = &n; // gán địa chỉ của biến n cho p
    
    std::cout << "n: Addr=" << &n << ", Val=" << n << std::endl;
    // địa chỉ, giá trị, giá trị tham chiếu
    std::cout << "p: Addr=" << &p << ", Val=" << p << ", ValRef=" << *p << std::endl;

    /* Con trỏ tham chiếu tới đối tượng động */
    int *pn = nullptr;
    // cấp phát vùng có kích thước kiểu int
    // và pn chứa địa chỉ vừa cấp phát
    pn = (int*) std::malloc(sizeof(int));
    (*pn) = 10; // gán 10 vào đối tượng pn tham chiếu
    
    std::cout << "sizeof(int): " << sizeof(int) << " byte(s)" << std::endl;
    // địa chỉ, giá trị, giá trị tham chiếu
    std::cout << "pn: Addr=" << &pn << ", Val=" << pn << ", ValRef=" << *pn << std::endl;
    
    // ! hủy vùng nhớ sau khi sử dụng xong
    std::free(pn);
    
    return 0;
}
