class Solution {
public:
    string reverseWords(string s) {
        string ans, word;
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        s += " ";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                if(s[i-1] == ' ') continue;
                if(ans == "") ans = word;
                else ans = word + " " + ans;
                word = "";
            }
            else word+= s[i];
        }
        return ans;
    }
};