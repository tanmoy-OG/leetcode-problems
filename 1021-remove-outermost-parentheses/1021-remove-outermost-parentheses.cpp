class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans;
        for(int i = 0; i < s.size(); i++) {
            if(st.size() == 1 && s[i] == ')') {
                st.pop();
                continue;
            }
            else if(!st.empty())
                ans+= s[i];
            if(s[i] == '(')
                st.push(s[i]);
            else
                st.pop();
        }
        return ans;
    }
};