class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = nums[i - 1];
            dp[i][1] = max(dp[i - 1][1] + nums[i - 1], dp[i][0]);
            dp[i][2] = min(dp[i - 1][2] + nums[i - 1], dp[i][0]);
            dp[i][3] = max({abs(dp[i][0]), abs(dp[i][2]), abs(dp[i][1]),
                            abs(dp[i - 1][3])});
        }
        return dp[n][3];
    }
};