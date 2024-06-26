#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: ";
    printArray(arr);

    auto start = high_resolution_clock::now();  
    insertionSort(arr);
    auto stop = high_resolution_clock::now();   
    auto duration = duration_cast<microseconds>(stop - start);  

    cout << "Sorted array: ";
    printArray(arr);
    cout << "Waktu eksekusi: " << duration.count() << " microseconds" << endl;

    return 0;
}