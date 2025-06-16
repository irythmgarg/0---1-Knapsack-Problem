# 0---1-Knapsack-Problem
# 🎒 0/1 Knapsack Problem - Dynamic Programming Approach 💻

## 📌 Problem Statement

You are given:

* A list of item **values** (`val[]`) 💰
* A list of item **weights** (`wt[]`) ⚖️
* A total **knapsack capacity** `W` 🎯

👉 Your task is to **maximize** the **total value** of items you can include in the knapsack **without exceeding** the capacity `W`.
Each item can either be included **once** or **not at all** (i.e., 0/1 property).

---

## 🧠 All Approaches Explained

### 1️⃣ Recursive Approach (Brute Force)

* **Idea**: For each item, decide to take it or skip it, and recurse accordingly.
* **Time Complexity**: `O(2^n)` (Exponential)
* **Space Complexity**: `O(n)` (Recursive stack)
* **Drawback**: Too slow for large inputs.

### 2️⃣ Top-Down DP (Memoization) ✨

* **Idea**: Use recursion, but store intermediate results in a 2D array `dp[i][W]` to avoid recalculating.
* **Time Complexity**: `O(n * W)`
* **Space Complexity**: `O(n * W)` for `dp` table + recursion stack
* **Benefit**: Optimized and readable. Uses memory to save time.

### 3️⃣ Bottom-Up DP (Tabulation) 📊

* **Idea**: Build up solution iteratively from smaller subproblems.
* **Time Complexity**: `O(n * W)`
* **Space Complexity**: `O(n * W)`
* **Benefit**: Efficient, avoids recursion. Generally faster than memoization.

### 4️⃣ Space-Optimized Bottom-Up DP 🔧

* **Idea**: Use two 1D arrays (or even one in reverse) since we only need the previous row.
* **Time Complexity**: `O(n * W)`
* **Space Complexity**: `O(W)`
* **Benefit**: Ideal for constrained memory environments.

---

## 💡 Approach: Bottom-Up Dynamic Programming (Tabulation)

### 🚶‍♂️ Step-by-Step Explanation

1. **Create a DP table** `dp[n+1][W+1]` where `dp[i][j]` represents the **maximum value** we can obtain with the first `i` items and a knapsack of capacity `j`.

2. **Initialize**:

   * `dp[i][0] = 0` → No capacity means no value.
   * `dp[0][j] = 0` → No items means no value.

3. **Iterate through items and capacities**:

   * For each item `i` and capacity `j`, decide whether to **include** or **exclude** the item:

     * If `wt[i-1] > j` → Cannot include item. Use value from previous row: `dp[i][j] = dp[i-1][j]`
     * Else → Include the item if beneficial:

       ```
       dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]])
       ```

4. **Final Answer**: `dp[n][W]` contains the maximum value we can achieve.

---

## ⏱️ Time and 📊 Space Complexity

* **Time Complexity**: `O(n * W)`
* **Space Complexity**: `O(n * W)`

Where `n` is the number of items and `W` is the capacity of the knapsack.

---

## 🔢 Example

```text
val =  [60, 100, 120]
wt  =  [10, 20, 30]
W = 50
```

We can take the 2nd and 3rd items for a total value of **220**.

---

## ⚖️ Comparison of Approaches

| Approach                     | Time Complexity | Space Complexity | Uses Memoization | Notes                           |
| ---------------------------- | --------------- | ---------------- | ---------------- | ------------------------------- |
| 🔄 Recursion (Brute Force)   | `O(2^n)`        | `O(n)` (stack)   | ❌                | Exponential and inefficient     |
| ✨ Top-Down DP (Memoization)  | `O(n * W)`      | `O(n * W)`       | ✅                | Faster, uses recursion + memory |
| 📊 Bottom-Up DP (Tabulation) | `O(n * W)`      | `O(n * W)`       | 🚫               | Iterative, stable               |
| 🔧 Space Optimized DP        | `O(n * W)`      | `O(W)`           | 🚫               | Compact and efficient           |

---

## 👤 Author Info

* **Name**: Ridham Garg
* **Role**: B.Tech Computer Engineering Student
* **University**: Thapar University, Patiala
* **Roll Number**: 102203014

---

📄 **Let me know if you'd like:**

* Visual diagrammatic explanation 🎨
* Python or C++ implementations 🔤
* Space-optimized code snippet 💾
