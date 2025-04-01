#include <iostream>
using namespace std;

int firstOccurrenceBinary(int arr[], int n, int x) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            result = mid;
            right = mid - 1; // Move left to find first occurrence
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int arr[] = {1, 2, 2, 4, 4, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    cout << "First occurrence of " << x << " is at index: " << firstOccurrenceBinary(arr, n, x) << endl;
    return 0;
}
