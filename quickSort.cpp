

#include <iostream>
#include <algorithm>
using namespace std;
// Phân hoạch Lomuto
int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; i < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i + 1], a[r]);
    return i + 1;
}
void quickSort(int a[], int l, int r) {
    if (l >= r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    quickSort(a, l, r);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

