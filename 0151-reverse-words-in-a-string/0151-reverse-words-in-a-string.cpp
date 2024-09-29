class Solution {
public:
    string reverseWords(string s) {
        string ans;
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ' && s[i + 1] != ' ' || i == 0) {
                string word;
                for (int j = i + 1; j < s.size() && s[j] != ' '; j++)
                    word += s[j];
                if (i == 0)
                    word = s[i] + word;
                else
                    word += " ";
                ans += word;
            }
        }
        return ans;
    }
};