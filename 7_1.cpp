#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum sponsorship value using Backtracking
void knapsackBacktrack(vector<int> &values, vector<int> &weights, int capacity, int index, int current_value, int current_weight, int &max_value) {
    // If budget exceeds, backtrack
    if (current_weight > capacity) return;

    // Update the maximum value found
    if (current_value > max_value) max_value = current_value;

    // If all items are processed, return
    if (index == values.size()) return;

    // Include the current sponsorship deal
    knapsackBacktrack(values, weights, capacity, index + 1, current_value + values[index], current_weight + weights[index], max_value);

    // Exclude the current sponsorship deal
    knapsackBacktrack(values, weights, capacity, index + 1, current_value, current_weight, max_value);
}

int main() {
    int n, capacity;
    cout << "Enter number of sponsorship deals: ";
    cin >> n;
    vector<int> values(n), weights(n);

    cout << "Enter sponsorship values: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    cout << "Enter budget requirements: ";
    for (int i = 0; i < n; i++) cin >> weights[i];

    cout << "Enter festival budget: ";
    cin >> capacity;

    int max_value = 0;
    knapsackBacktrack(values, weights, capacity, 0, 0, 0, max_value);

    cout << "Maximum sponsorship value: " << max_value << endl;
    return 0;
}
