#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    // Create a DP table with all elements initialized to 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {  // If characters match
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {  // Otherwise, take the max value from previous results
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];  // The length of the longest common subsequence
}

int main() {
    string s1, s2;
    cout << "Enter DNA Sequence 1: ";
    cin >> s1;
    cout << "Enter DNA Sequence 2: ";
    cin >> s2;

    int lcs_length = longestCommonSubsequence(s1, s2);
    cout << "Length of Longest Common DNA Subsequence: " << lcs_length << endl;

    return 0;
}
