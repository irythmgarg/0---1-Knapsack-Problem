int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size();
    
    // Create a DP table where dp[i][j] will store the maximum value
    // that can be attained with the first i items and capacity j
    int dp[n + 1][W + 1];

    // Initialize the base cases:
    // If there are 0 items, profit is 0 regardless of capacity
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    // If capacity is 0, profit is 0 regardless of number of items
    for (int j = 0; j <= W; j++)
        dp[0][j] = 0;

    // Fill the DP table using bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] > j) {
                // If current item's weight is more than current capacity,
                // we can't include this item, so take the value from above
                dp[i][j] = dp[i - 1][j];
            } else {
                // Either take the item or don't take it
                // - If we take it: add its value + profit from remaining capacity
                // - If we don't: profit remains the same as above row
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }

    // The bottom-right corner will have the final answer
    return dp[n][W];
}
