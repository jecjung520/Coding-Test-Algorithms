using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
public:
  int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity) {
    // basic checks
    if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) {
      return 0;
    }

    int n = profits.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1));

    // populate the capacity=0 columns, with '0' capacity we have '0' profit
    for (int i = 0; i < n; i++) {
      dp[i][0] = 0;
    }

    // if we have only one weight, we will take it if it is not more than the capacity
    for (int c = 0; c <= capacity; c++) {
      if (weights[0] <= c) {
        dp[0][c] = profits[0];
      }
    }

    // process all sub-arrays for all the capacities
    for (int i = 1; i < n; i++) {
      for (int c = 1; c <= capacity; c++) {
        int profit1 = 0, profit2 = 0;
        // include the item, if it is not more than the capacity
        if (weights[i] <= c) {
          profit1 = profits[i] + dp[i - 1][c - weights[i]];
        }
        // exclude the item
        profit2 = dp[i - 1][c];
        // take maximum
        dp[i][c] = max(profit1, profit2);
      }
    }

    // maximum profit will be at the bottom-right corner.
    return dp[n - 1][capacity];
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
}
