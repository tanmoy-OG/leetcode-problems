class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size() / 2; i++) {
            for (int j = pos; j < nums.size(); j++)
                if (nums[j] >= 0) {
                    pos = j + 1;
                    ans.push_back(nums[j]);
                    break;
                }
            for (int k = neg; k < nums.size(); k++)
                if (nums[k] < 0) {
                    neg = k + 1;
                    ans.push_back(nums[k]);
                    break;
                }
        }
        return ans;
    }
};