class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end())
            return 0;
        queue<pair<string, int>> q;
        st.erase(beginWord);
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
    void nextWord(int i, string word, unordered_set<string>& st, queue<pair<string, int>>& q, int lvl) {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            word[i] = ch;
            if(st.find(word) != st.end()) {
                q.push({word, lvl+1});
                st.erase(word);
            }
        }
    }
};