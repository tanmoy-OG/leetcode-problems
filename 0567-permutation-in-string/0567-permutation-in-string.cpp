class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for (auto ch : s1)
            mp1[ch]++;

        int i = 0, j = 0, n1 = s1.size(), n2 = s2.size();
        while (j < n2) {
            mp2[s2[j++]]++;
            if (j - i == n1) {
                if (mp2 == mp1)
                    return true;
                mp2[s2[i]]--;
                if (mp2[s2[i]] == 0)
                    mp2.erase(s2[i]);
                i++;
            }
        }
        return false;
    }
};