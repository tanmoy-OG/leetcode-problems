class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto it: wordList)
            st.insert(it);
        if(st.find(endWord) == st.end())
            return 0;
        queue<pair<string, int>> q;
        if(st.find(beginWord) != st.end())
            st.erase(st.find(beginWord));
        q.push({beginWord, 1});
        while(!q.empty()) {
            string word = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(word == endWord)
                return lvl;
            for(int i = 0; i < word.size(); i++)
                nextWord(i, word, st, q, lvl);
        }
        return 0;
    }
    void nextWord(int i, string word, set<string>& st, queue<pair<string, int>>& q, int lvl) {
        string temp = word;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            temp[i] = ch;
            auto it = st.find(temp);
            if(word != temp && it != st.end()) {
                q.push({temp, lvl+1});
                st.erase(it);
            }
        }
    }
};