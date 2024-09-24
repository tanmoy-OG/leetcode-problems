class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size(), idealSum = size * (size + 1) / 2, realSum = 0,
            missing;
        for (auto it : nums)
            realSum += it;
        missing = idealSum - realSum;
        return missing;
    }
};