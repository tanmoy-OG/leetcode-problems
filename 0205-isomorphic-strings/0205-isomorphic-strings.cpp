class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            char ch1 = s[i];
            char ch2 = t[i];
            for (int j = i; j < s.size(); j++)
                if (s[j] == ch1 && t[j] != ch2 || t[j] == ch2 && s[j] != ch1)
                    return false;
        }
        return true;
    }
};