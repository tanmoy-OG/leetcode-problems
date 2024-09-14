class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size() && j < nums.size()) {
            if (nums[i] == 0) {
                if (nums[j] == 0)
                    j++;
                else {
                    swap(nums, i, j);
                    i++;
                    j++;
                }
            } else {
                i++;
                j++;
            }
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};