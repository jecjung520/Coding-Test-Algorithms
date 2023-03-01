using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
  int canPartition(const vector<int> &num) { 
    int sum = 0, n = num.size();
    for (int i: num)
        sum += i;

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return this->canPartitionRecursive(dp, num, 0, 0, 0); 
  }

private:
  int canPartitionRecursive(vector<vector<int>>& dp, const vector<int> &num, int currentIndex, int sum1, int sum2) {
    // base check
    if (currentIndex == num.size()) {
      return abs(sum1 - sum2);
    }

    if (dp[currentIndex][sum1] == -1) {
        // recursive call after including the number at the currentIndex in the first set
        int diff1 = canPartitionRecursive(dp, num, currentIndex + 1, sum1 + num[currentIndex], sum2);

        // recursive call after including the number at the currentIndex in the second set
        int diff2 = canPartitionRecursive(dp, num, currentIndex + 1, sum1, sum2 + num[currentIndex]);

        dp[currentIndex][sum1] = min(diff1, diff2);
    }

    return dp[currentIndex][sum1];
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}