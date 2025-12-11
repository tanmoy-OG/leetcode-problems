class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), maxi = 1;
        if (n == 0)
            return 0;
        unordered_set<int> st;
        for (auto it : nums)
            st.insert(it);
        for (auto it : st)
            if (st.find(it - 1) == st.end()) {
                int cnt = 1, x = it;
                while (st.find(x + 1) != st.end()) {
                    cnt++;
                    x++;
                }
                maxi = max(maxi, cnt);
            }
        return maxi;
    }
};