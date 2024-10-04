class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int ans = 0, n = skill.size(), teams = n / 2, eq;
        sort(skill.begin(), skill.end());
        eq = skill[0] + skill[n - 1];
        for (int i = 0; i < teams; i++) {
            if (skill[i] + skill[n - i - 1] != eq)
                return -1;
            else
                ans += (skill[i] * skill[n - i - 1]);
        }
        return ans;
    }
};