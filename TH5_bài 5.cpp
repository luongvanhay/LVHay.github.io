#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Hàm kiểm tra xem một nút có phải là nút một nhánh con hay không
bool laNutMotNhanh(Node* node) {
    return (node->left == nullptr && node->right != nullptr) ||
        (node->left != nullptr && node->right == nullptr);
}

// Công thức đệ quy để tính tổng số nút có một nhánh con
int tinhTongSoNutMotNhanh(Node* root) {
    if (root == nullptr) return 0; // Trường hợp cây rỗng
    int soNutMotNhanh = laNutMotNhanh(root) ? 1 : 0;
    return soNutMotNhanh + tinhTongSoNutMotNhanh(root->left) + tinhTongSoNutMotNhanh(root->right);
}

// Hàm duyệt cây theo NLR (duyệt nút gốc giữa)
void duyetNLR(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";   // Nút gốc
    duyetNLR(root->left);        // Duyệt nhánh con trái
    duyetNLR(root->right);       // Duyệt nhánh con phải
}

// Hàm main để kiểm tra chương trình
int main() {
    // Tạo cây nhị phân mẫu
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = nullptr;
    root->right->left = nullptr;
    root->right->right = new Node(5);

    // Duyệt cây theo thứ tự NLR
    cout << "Duyet cay theo NLR: ";
    duyetNLR(root);
    cout << endl;

    // Tính tổng số nút có một nhánh con
    int tongNutMotNhanh = tinhTongSoNutMotNhanh(root);
    cout << "Tong so nut co mot nhanh con: " << tongNutMotNhanh << endl;

    return 0;
}