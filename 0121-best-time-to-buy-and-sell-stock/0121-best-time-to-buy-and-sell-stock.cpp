class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mini = INT_MAX;
        for (auto it : prices) {
            mini = min(mini, it);
            profit = max(profit, it - mini);
        }
        return profit;
    }
};