#include< iostream>
using namespace std;
// Thuật toán sắp xếp chọn selectionsort 
void selectionsort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}
void bubblesort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
void insertionsort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
void recur(int n) {
	if (n <= 1)return;
	recur(n - 1);
	for (int i = 0; i < n; i++) {
		cout << i << " ";

	}
}
int main() {
	int n; cin >> n;
	recur(n);

}