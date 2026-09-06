class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long sum1 = 0, sum2 = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i < nums.size()/2)
                sum1 += nums[i];
            else
                sum2 += nums[i];
        }
        int i = 0, j = nums.size()/2;
        while(i < nums.size()) {
            sum1 = sum1 - nums[i] + nums[j];
            sum2 = sum2 - nums[j] + nums[i];
            i++;
            j++;
            if(j == nums.size())
                j = 0;
            if(sum1 > sum2)
                cnt++;
        }
        return cnt;
    }
};