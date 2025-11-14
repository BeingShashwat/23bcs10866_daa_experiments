// Find frequency of elements in a given array in O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> occurrences;
    vector<int> sequence;

    for (int item : arr) {
        if (occurrences[item] == 0) {
            sequence.push_back(item);
        }
        occurrences[item]++;
    }

    cout << "\nElement occurrences:\n";
    for (int item : sequence) {
        cout << item << " appears " << occurrences[item] << " time(s)" << endl;
    }

    return 0;
}
