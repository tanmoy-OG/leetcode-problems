class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int value = (i + 1) * (26 - (s[i] - 'a'));
            sum += value;
        }
        return sum;
    }
};