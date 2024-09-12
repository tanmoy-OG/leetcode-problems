class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0 || nums.size() == 1)
            return;
        k = k % nums.size();
        if (nums.size() < k)
            return;
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};