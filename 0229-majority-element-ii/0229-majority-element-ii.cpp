class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int check = 0;
            int freq = 0;
            for(auto it: ans)
                if(it == nums[i]) {
                    check = 1;
                    break;
                }
            if(check == 1)
                continue;
            for(int j = i; j < nums.size(); j++)
                if(nums[i] == nums[j])
                    freq++;
            if(freq > nums.size()/3)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};