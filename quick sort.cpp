#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {846, 22, 424, 232, 242, 24242};
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();  

    quickSort(arr, 0, arr.size() - 1);

    auto stop = high_resolution_clock::now();   
    auto duration = duration_cast<microseconds>(stop - start); 

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Waktu eksekusi: " << duration.count() << " mikrodetik" << endl;

    return 0;
}