class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = INT_MIN;
        for (auto it : piles)
            n = max(n, it);
        int start = 1, end = n;
        while (start <= end) {
            long sum = 0, mid = (start+end)/2;
            for (auto it : piles)
                sum += ceil((double)it / (double)mid);
            if (sum <= h)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
};