// heapsort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
using namespace std;
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i+1;
    int r = 2 * i + 2;
    if (l<n && a[l]>a[largest]) {
        largest = l;
    }
    if (r<n && a[r]> a[largest]) {
        largest = r;
    }
    if (largest != i) {
       std::swap(a[i], a[largest]);
        heapify(a, n, largest);
    }   
}
void heapSort(int a[], int n) {
    for (int i= n / 2 - 1; i >= 0; i--) {// xây dựng max heap
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
       std::swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

int main()
{
    int a[1000], n=1000;
    
    srand(( unsigned)time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 500;
    }
    heapSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

