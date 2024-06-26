#include <bits/stdc++.h>
#include <chrono>

using namespace std;
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << std::endl;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "array awal: ";
    printArray(arr);

    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr);
    auto end = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    printArray(arr);

    chrono::duration<double> duration = end - start;
    cout << "waktu eksekusi: " << duration.count() << " seconds" << std::endl;

    return 0;
}