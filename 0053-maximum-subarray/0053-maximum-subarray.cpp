class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0, j = 0, sum = 0, maxi = INT_MIN;
        while(i < nums.size() && j < nums.size()) {
            sum+= nums[j];
            j++;
            maxi = max(maxi, sum);
            if(sum < 0) {
                sum = 0;
                i = j;
            }
        }
        return maxi;
    }
};