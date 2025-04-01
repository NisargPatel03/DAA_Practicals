#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findMissingNumbers(int n, vector<int>& nums) {
    vector<int> result;

    // Mark the elements that are present in the array
    for (int i = 0; i < nums.size(); i++) {
        int num = abs(nums[i]);  // Get the absolute value to handle negative numbers
        if (num <= n && nums[num - 1] > 0) {
            nums[num - 1] = -nums[num - 1];  // Mark the number as visited (negate the value)
        }
    }

    // Collect all the missing numbers
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);  // If the number is positive, it's missing
        }
    }

    return result;
}

int main() {
    int n = 10;  // Range from 1 to 10
    vector<int> nums = {1, 2, 2, 4, 5, 6, 8, 10, 10};

    vector<int> missingNumbers = findMissingNumbers(n, nums);

    cout << "Missing numbers: ";
    for (int num : missingNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
