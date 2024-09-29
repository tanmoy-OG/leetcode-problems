class Solution {
public:
    int maxDepth(string s) {
        int maxi = INT_MIN, cnt = 0;
        for (auto it : s) {
            if (it == '(')
                cnt++;
            else if (it == ')')
                cnt--;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};