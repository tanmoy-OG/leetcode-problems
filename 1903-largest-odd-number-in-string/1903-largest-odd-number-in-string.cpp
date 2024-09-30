class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int maxi = 0;
        for (int i = 0; i < num.size(); i++) {
            if ((int)num[i] % 2 == 1) {
                string sb;
                for (int j = 0; j <= i; j++)
                    sb += num[j];
                if (sb.size() > maxi) {
                    maxi = sb.size();
                    ans = sb;
                }
            }
        }
        return ans;
    }
};