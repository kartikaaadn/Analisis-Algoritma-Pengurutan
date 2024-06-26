#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
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

    auto start = chrono::high_resolution_clock::now();  
    selectionSort(arr);

    auto stop = chrono::high_resolution_clock::now();   
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);  

    cout << "Sorted array: ";
    printArray(arr);

    cout << "Waktu eksekusi: " << duration.count() << " microseconds" << endl;

    return 0;
}