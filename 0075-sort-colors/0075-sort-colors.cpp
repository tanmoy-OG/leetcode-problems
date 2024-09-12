class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, check = 0;
        while (i < nums.size() && check <= 1) {
            if (nums[i] == check) {
                i++;
                if (j < i)
                    j++;
                continue;
            }
            if (j >= nums.size()) {
                j = i;
                check++;
                continue;
            }
            if (nums[j] == check && nums[i] > nums[j]) {
                nums[j] = nums[i];
                nums[i] = check;
                i++;
            }
            j++;
        }
    }
};