#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Function to compute the minimum scalar multiplications
int matrixChainMultiplication(vector<int> &dims) {
    int n = dims.size() - 1;  // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Length of chain being considered
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try all possible partitions
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];  // Minimum cost for multiplying A1...An
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> dims(n + 1);
    cout << "Enter matrix dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> dims[i];
    }

    int minMultiplications = matrixChainMultiplication(dims);
    cout << "Minimum number of scalar multiplications: " << minMultiplications << endl;

    return 0;
}
