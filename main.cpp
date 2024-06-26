#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
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

// Insertion Sort
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

// Selection Sort
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

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Quick Sort
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

    // Bubble Sort
    vector<int> bubbleArr = arr;
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(bubbleArr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Bubble Sort: ";
    printArray(bubbleArr);
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    // Insertion Sort
    vector<int> insertionArr = arr;
    start = high_resolution_clock::now();  
    insertionSort(insertionArr);
    end = high_resolution_clock::now();   
    duration = end - start;
    cout << "Insertion Sort: ";
    printArray(insertionArr);
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    // Selection Sort
    vector<int> selectionArr = arr;
    start = chrono::high_resolution_clock::now();  
    selectionSort(selectionArr);
    end = chrono::high_resolution_clock::now();   
    duration = end - start;
    cout << "Selection Sort: ";
    printArray(selectionArr);
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    // Merge Sort
    vector<int> mergeArr = arr;
    start = chrono::high_resolution_clock::now();  
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    end = chrono::high_resolution_clock::now();   
    duration = end - start;
    cout << "Merge Sort: ";
    printArray(mergeArr);
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    // Quick Sort
    vector<int> quickArr = arr;
    start = high_resolution_clock::now();  
    quickSort(quickArr, 0, quickArr.size() - 1);
    end = high_resolution_clock::now();   
    duration = end - start;
    cout << "Quick Sort: ";
    printArray(quickArr);
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}