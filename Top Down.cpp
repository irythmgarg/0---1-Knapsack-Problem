// Global DP array for memoization: dp[i][W] stores max value for items from i to end with capacity W
int dp[1001][1001];

// Recursive helper function to compute maximum value with memoization
int hlo(int W, vector<int> &val, vector<int> &wt, int i) {
    // Base case: if all items have been considered
    if (i >= wt.size())
        return 0;

    // If result already computed, return it
    if (dp[i][W] != -1)
        return dp[i][W];

    int take = 0;

    // Option 1: Take the item if it fits in the current capacity
    if (W >= wt[i])
        take = val[i] + hlo(W - wt[i], val, wt, i + 1);  // include current item

    // Option 2: Don't take the item
    int nottake = hlo(W, val, wt, i + 1);  // skip current item

    // Memoize and return the maximum of taking or not taking
    return dp[i][W] = max(take, nottake);
}

// Main function to initialize DP and start recursion
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // Initialize the memoization table with -1 (uncomputed)
    memset(dp, -1, sizeof(dp));

    // Start from index 0 with full capacity W
    return hlo(W, val, wt, 0);
}
