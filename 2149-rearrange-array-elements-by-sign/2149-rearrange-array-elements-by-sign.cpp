class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 0, check = 1;
        vector<int> ans;
        while (pos < nums.size() && neg < nums.size()) {
            if (check == 1 && nums[pos] >= 0) {
                ans.push_back(nums[pos]);
                pos++;
                check = 0;
            } else if (check == 1 && nums[pos] < 0)
                pos++;
            if (check == 0 && nums[neg] < 0) {
                ans.push_back(nums[neg]);
                neg++;
                check = 1;
            } else if (check == 0 && nums[neg] >= 0)
                neg++;
        }
        while (pos < nums.size()) {
            if (nums[pos] >= 0)
                ans.push_back(nums[pos]);
            pos++;
        }
        while (neg < nums.size()) {
            if (nums[neg] < 0)
                ans.push_back(nums[neg]);
            neg++;
        }
        return ans;
    }
};