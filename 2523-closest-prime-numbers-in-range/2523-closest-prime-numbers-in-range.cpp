class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1, -1};
        int temp = INT_MAX;
        while (right >= left) {
            if (prime(right) == 1 && ans[1] == -1) {
                ans[1] = right;
                temp = right;
            } else if (prime(right) == 1) {
                if (ans[0] == -1)
                    ans[0] = right;
                else {
                    if (ans[1] - ans[0] >= ans[0] - right) {
                        ans[1] = ans[0];
                        ans[0] = right;
                    } else if (ans[1] - ans[0] >= temp - right) {
                        ans[1] = temp;
                        ans[0] = right;
                    }
                }
                temp = right;
            }
            right--;
        }
        if (ans[0] == -1)
            ans[1] = -1;
        return ans;
    }
    int prime(int num) {
        int cnt = 0;
        if (num <= 1)
            return -1;
        else {
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0)
                    cnt++;
            }
            if (cnt > 0)
                return -1;
        }
        return 1;
    }
};