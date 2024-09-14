class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size() / 2, ans = 0;

        for (auto a : nums) {
            mp[a]++;
        }
        for (auto a : mp) {
            if (a.second > n) {
                ans = a.first;
            }
        }

        return ans;
    }
};