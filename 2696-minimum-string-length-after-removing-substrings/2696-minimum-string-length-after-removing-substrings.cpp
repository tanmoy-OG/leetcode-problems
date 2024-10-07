class Solution {
public:
    int minLength(string s) {
        string ans = "";
        stack<char> st;
        for (char it : s) {
            if (st.empty())
                st.push(it);
            else if (it == 'B' && st.top() == 'A')
                st.pop();
            else if (it == 'D' && st.top() == 'C')
                st.pop();
            else
                st.push(it);
        }
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans.size();
    }
};