class Solution {
public:
    bool check(vector<int>& nums) {
        int check = 0, size = nums.size();
        for (int i = 1; i < size; i++) {
            if (nums[i] < nums[i - 1])
                check++;
            if (check > 1)
                return false;
        }
        if (check == 1 && nums[0] < nums[size - 1])
            return false;
        return true;
    }
};