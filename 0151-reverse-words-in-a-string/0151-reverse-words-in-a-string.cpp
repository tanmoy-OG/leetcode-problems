class Solution {
public:
    string reverseWords(string s) {
        string ans, word;
        int i = 0, j = 0;
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        s += " ";
        while (i < s.size() && j < s.size()) {
            if (s[i] == ' ' && i != j) {
                word += s[j];
                j++;
            } else if (s[i] == ' ' && i == j) {
                if (!word.empty()) {
                    ans = word + " " + ans;
                    word = "";
                }
                i++;
                j++;
            } else
                i++;
        }
        ans.erase(ans.find_last_not_of(" ") + 1);
        return ans;
    }
};