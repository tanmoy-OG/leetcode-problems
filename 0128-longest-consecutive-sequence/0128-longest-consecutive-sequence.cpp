class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = 0, last = INT_MIN, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == last + 1) {
                last = nums[i];
                cnt++;
                maxi = max(maxi, cnt);
            } else if (nums[i] > last + 1) {
                last = nums[i];
                cnt = 1;
            }
        }
        return maxi;
    }
};