class Solution {
public:
    using ll = long long;
    ll ceildiv(ll a, ll b) { return (a + b - 1) / b; }
    long long maxKelements(vector<int>& nums, int k) {
        ll score = 0;
        priority_queue<int> pq;

        for (auto& x : nums)
            pq.push(x);

        while (k--) {
            int t = pq.top();
            pq.pop();
            score += t;
            pq.push(ceildiv(t, 3));
        }

        return score;
    }
};