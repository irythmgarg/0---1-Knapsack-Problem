// Recursive function to solve 0/1 Knapsack problem
int hlo(int W, vector<int> &val, vector<int> &wt, int i) {
    // Base case: No more items to consider
    if (i >= wt.size())
        return 0;

    int take = 0;

    // Option 1: Take the current item if it fits in the remaining capacity
    if (W >= wt[i])
        take = val[i] + hlo(W - wt[i], val, wt, i + 1);  // Include item i

    // Option 2: Skip the current item
    int nottake = hlo(W, val, wt, i + 1);  // Exclude item i

    // Return the maximum of including or excluding the current item
    return max(take, nottake);
}

// Wrapper function to start the recursive knapsack process
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    return hlo(W, val, wt, 0);  // Start from item 0 and full capacity W
}
