class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mp;
        multimap<int, char> mmp;
        for(auto it: s)
            mp[it]++;
        for(auto it: mp)
            mmp.insert(make_pair(it.second, it.first));
        for(auto it: mmp)
            ans = string(it.first, it.second) + ans;
        return ans;
    }
};