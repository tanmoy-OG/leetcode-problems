class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i <= nums.size(); i++) {
            int check = 0;
            for (auto it : nums)
                if (it == i) {
                    check++;
                    break;
                }
            if (check == 0)
                return i;
        }
        return -1;
    }
};