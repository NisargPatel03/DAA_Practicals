#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {  // Iterate through items
        for (int w = 0; w <= capacity; w++) {  // Iterate through all weight capacities
            if (weights[i - 1] <= w) {  // If the current item fits in the truck
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {  // If the current item does not fit, inherit the previous value
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];  // Maximum value at full capacity
}

int main() {
    vector<int> weights = {2, 3, 4, 5};  // Supply weights
    vector<int> values = {3, 4, 5, 6};   // Supply values
    int capacity = 5;                     // Truck capacity

    int max_value = knapsack(weights, values, capacity);
    cout << "Maximum value of supplies that can be transported: " << max_value << endl;

    return 0;
}
