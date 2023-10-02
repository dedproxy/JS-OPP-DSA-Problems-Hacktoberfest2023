#include <vector>
#include <algorithm>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n) {
    // Calculate the total sum of elements in the array.
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Create a DP table to store subset sum information.
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

    // Initialize the DP table for the base case.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Find the minimum difference between subset sums.
    int minDiff = INT_MAX;
    for (int j = totalSum / 2; j >= 0; j--) {
        if (dp[n][j]) {
            minDiff = totalSum - 2 * j;
            break;
        }
    }

    return minDiff;
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    int n = arr.size();
    
    int minDiff = minSubsetSumDifference(arr, n);
    cout << "Minimum Subset Sum Difference: " << minDiff << endl;
    
    return 0;
}
