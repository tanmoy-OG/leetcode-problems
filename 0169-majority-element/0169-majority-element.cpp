class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, cnt = 0;

        for (auto it : nums) {
            if (cnt == 0)
                ans = it;
            if (ans == it)
                cnt++;
            else
                cnt--;
        }

        cnt = 0;
        for (auto it : nums)
            if (ans == it)
                cnt++;

        return cnt > ceil(nums.size() / 2) ? ans : 0;
    }
};