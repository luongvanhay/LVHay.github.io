#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm tính tổng và đếm số nút
double tinhTong(TreeNode* root, int& count) {
    if (!root) return 0;

    double leftSum = tinhTong(root->left, count);
    double rightSum = tinhTong(root->right, count);

    count++;
    return leftSum + rightSum + root->val;
}

// Hàm tính trung bình cộng của tất cả các nút trong cây
double tinhTrungBinhCong(TreeNode* root) {
    int count = 0;
    double sum = tinhTong(root, count);
    return count > 0 ? sum / count : 0;
}

// Hàm tính tổng và đếm các số dương
double tinhTongDuong(TreeNode* root, int& count) {
    if (!root) return 0;

    double leftSum = tinhTongDuong(root->left, count);
    double rightSum = tinhTongDuong(root->right, count);

    if (root->val > 0) {
        count++;
        return leftSum + rightSum + root->val;
    }
    return leftSum + rightSum;
}

// Hàm tính trung bình cộng các số dương
double tinhTrungBinhCongDuong(TreeNode* root) {
    int count = 0;
    double sum = tinhTongDuong(root, count);
    return count > 0 ? sum / count : 0;
}

// Hàm tính tổng và đếm các số âm
double tinhTongAm(TreeNode* root, int& count) {
    if (!root) return 0;

    double leftSum = tinhTongAm(root->left, count);
    double rightSum = tinhTongAm(root->right, count);

    if (root->val < 0) {
        count++;
        return leftSum + rightSum + root->val;
    }
    return leftSum + rightSum;
}

// Hàm tính trung bình cộng các số âm
double tinhTrungBinhCongAm(TreeNode* root) {
    int count = 0;
    double sum = tinhTongAm(root, count);
    return count > 0 ? sum / count : 0;
}

// Hàm tính tổng các số dương
double tongDuong(TreeNode* root) {
    if (!root) return 0;

    double leftSum = tongDuong(root->left);
    double rightSum = tongDuong(root->right);

    return root->val > 0 ? leftSum + rightSum + root->val : leftSum + rightSum;
}

// Hàm tính tổng các số âm
double tongAm(TreeNode* root) {
    if (!root) return 0;

    double leftSum = tongAm(root->left);
    double rightSum = tongAm(root->right);

    return root->val < 0 ? leftSum + rightSum + root->val : leftSum + rightSum;
}

// Hàm tính tỷ số R = a / b
double tinhTiSo(TreeNode* root) {
    double a = tongDuong(root);
    double b = tongAm(root);
    return b != 0 ? a / b : 0;
}
int main() {
    // Tạo cây nhị phân mẫu
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(-3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(-2);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(-4);
    cout << "Trung binh cong tat ca cac nut: " << tinhTrungBinhCong(root) << endl;
    cout << "Trung binh cong cac so duong: " << tinhTrungBinhCongDuong(root) << endl;
    cout << "Trung binh cong cac so am: " << tinhTrungBinhCongAm(root) << endl;
    cout << "Ty so R = a / b: " << tinhTiSo(root) << endl;

    return 0;
}