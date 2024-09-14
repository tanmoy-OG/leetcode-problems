class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> store;

        for (auto it : nums)
            if (it != 0)
                store.push_back(it);
        int cnt = nums.size() - store.size();
        for (int i = 1; i <= cnt; i++)
            store.push_back(0);

        nums = store;
    }
};