class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> store;
        int cnt = 0;

        for (auto it : nums) {
            if (it == 0)
                cnt++;
            else
                store.push_back(it);
        }
        for (int i = 1; i <= cnt; i++)
            store.push_back(0);

        nums = store;
    }
};