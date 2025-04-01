#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;  // Map to store the number and its index
    vector<int> result;              // To store the indices of the two numbers

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // If the complement is found in the map, return the indices
        if (numMap.find(complement) != numMap.end()) {
            result.push_back(numMap[complement]);
            result.push_back(i);
            return result;
        }

        // Otherwise, store the current number with its index
        numMap[nums[i]] = i;
    }

    return result;  // In case there is no solution (should not happen as per problem statement)
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices of the two numbers that add up to " << target << ": ";
        cout << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
