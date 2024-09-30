class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "", prefix = "";
        for (int i = 0; i < strs[0].size(); i++) {
            prefix += strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                string sb = strs[j].substr(0, i + 1);
                if (sb != prefix)
                    return ans;
            }
            ans = prefix;
        }
        return ans;
    }
};