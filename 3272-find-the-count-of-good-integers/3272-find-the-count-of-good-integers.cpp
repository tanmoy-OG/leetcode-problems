#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countGoodIntegers(int n, int k) {
        int start = pow(10, n - 1);
        int end = pow(10, n) - 1;
        int ans = 0;
        unordered_map<string, bool> memo;

        for (int i = start; i <= end; ++i) {
            string sortedDigits = getSortedDigits(i);
            if (memo.find(sortedDigits) == memo.end()) {
                memo[sortedDigits] = hasPalindromePermutation(i, k);
            }
            if (memo[sortedDigits]) {
                ans++;
            }
        }

        return ans;
    }

private:
    string getSortedDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }

    bool hasPalindromePermutation(int num, int k) {
        string s = to_string(num);
        set<string> permutations;
        generatePermutations(s, 0, permutations);

        for (const string& perm : permutations) {
            if (perm[0] == '0')
                continue;
            if (isPalindrome(perm) && stoi(perm) % k == 0) {
                return true;
            }
        }

        return false;
    }

    void generatePermutations(string& s, int index, set<string>& result) {
        if (index == s.length() - 1) {
            result.insert(s);
            return;
        }

        for (int i = index; i < s.length(); ++i) {
            swap(s[index], s[i]);
            generatePermutations(s, index + 1, result);
            swap(s[index], s[i]); // backtrack
        }
    }

    bool isPalindrome(const string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};