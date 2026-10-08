class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt1 = 0, cnt2 = 0;
        for (auto it : s) {
            if (it == '(')
                cnt1++;
            else
                cnt2++;
            if (cnt1 > 1 && cnt1 != cnt2)
                ans += it;
            else if (cnt1 == cnt2) {
                cnt1 = 0;
                cnt2 = 0;
            }
        }
        return ans;
    }
};