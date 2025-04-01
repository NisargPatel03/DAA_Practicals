#include <iostream>
#include <vector>

using namespace std;

// Partition function for Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> parcels = {50, 20, 10, 40, 30, 60, 90, 80};
    cout << "Unsorted Parcel Weights: ";
    displayArray(parcels);

    quickSort(parcels, 0, parcels.size() - 1);

    cout << "Sorted Parcel Weights (Quick Sort): ";
    displayArray(parcels);

    return 0;
}
