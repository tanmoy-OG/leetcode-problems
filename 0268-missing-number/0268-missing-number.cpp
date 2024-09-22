class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> store(nums.size()+1);
        for(auto it: nums)
            store[it] = 1;
        for(int i = 0; i < store.size(); i++)
            if(store[i] == 0)
                return i;
        return 0;
    }
};