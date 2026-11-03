class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN, ans = 0;
        for(int it: nums)
            maxi = max(maxi, it);
        for(int it: nums)
            ans += maxi-it;
        return ans;
    }
};