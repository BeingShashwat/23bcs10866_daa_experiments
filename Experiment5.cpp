// Quick sort

#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // pivot element
    int i = low - 1;        // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort Function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);   // Sort left side
        quickSort(arr, pi + 1, high);  // Sort right side
    }
}

int main() {
    int arraySize;
    cout << "Input array length: ";
    cin >> arraySize;

    vector<int> dataset(arraySize);
    cout << "Input array values: ";
    for (int i = 0; i < arraySize; i++) 
        cin >> dataset[i];

    quickSort(dataset, 0, arraySize - 1);

    cout << "Sorted output: ";
    for (int value : dataset) 
        cout << value << " ";
    cout << endl;

    return 0;
}
