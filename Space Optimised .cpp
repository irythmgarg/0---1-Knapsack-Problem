int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size(); // Number of items

    // Initialize 2 rows for DP to save space (previous and current)
    int dp[2][W + 1];

    // Base case: when no items or zero capacity, max value is 0
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;
    dp[1][0] = 0;

    // Loop through all items
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            // If current item weight is more than capacity, we cannot include it
            if (wt[i - 1] > j)
                dp[1][j] = dp[0][j]; // Exclude item
            else
                // Take the max of excluding or including the current item
                dp[1][j] = max(dp[0][j], val[i - 1] + dp[0][j - wt[i - 1]]);
        }

        // Copy current row to previous row for next iteration
        for (int j = 0; j <= W; j++)
            dp[0][j] = dp[1][j];
    }

    // Final answer is in the last cell of current row
    return dp[1][W];
}
