/*
 * Author: Muxammadjon Axmadjonov
 * Date: 23/01/2024
 * Name: hw-11
 */

#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    // If the sum of all numbers cannot be partitioned into two subsets with the given target difference, return 0
    if ((sum + target) % 2 != 0) {
        return 0;
    }

    int subsetSum = (sum + target) / 2; 
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, 0));

    // Base cases:
    dp[0][0] = 1; // Empty set can form a sum of 0
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1; // Empty subset can be formed from any set
    }

   
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= subsetSum; j++) {
            if (nums[i - 1] <= j) {
                // Include the current number:
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            } else {
                // Exclude the current number:
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][subsetSum];
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int ways = findTargetSumWays(nums, target);
    cout << "Number of ways: " << ways << endl;
    return 0;
}
