class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, ans = 0;
        for (char ch : s) {
            if (ch == '(')
                cnt++;
            else if (ch == ')')
                cnt--;
            if (cnt < 0) {
                ans++;
                cnt++;
            }
        }
        ans += cnt;
        return ans;
    }
};