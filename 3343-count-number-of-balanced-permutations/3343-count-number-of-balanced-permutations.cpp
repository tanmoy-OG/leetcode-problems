constexpr long long mod = 1e9 + 7;

static constexpr auto PascalTriangle() {
    std::array<std::array<long long, 41>, 41> a{};

    for (int i = 0; i < 41; ++i) {
        a[i][0] = a[i][i] = 1;
        for (int j = 1; j <= i / 2; ++j) {
            long long x = a[i - 1][j - 1] + a[i - 1][j];
            if (x >= mod)
                x -= mod;
            a[i][j] = a[i][i - j] = x;
        }
    }
    return a;
}

class Solution {
public:
    static constexpr auto comb = PascalTriangle();
    std::array<int, 10> freq{};
    int sum = 0, n = 0;
    std::unordered_map<unsigned, unsigned> dp;

    unsigned f(int i, int even, int odd, int remain) {
        if (even == 0 && odd == 0 && remain == 0)
            return 1;
        if (i < 0 || even < 0 || odd < 0 || remain < 0)
            return 0;

        unsigned key = (i << 21) | (even << 15) | (odd << 9) | remain;
        if (auto it = dp.find(key); it != dp.end())
            return it->second;

        long long ans = 0;
        int max_j = std::min(freq[i], even);
        for (int j = 0; j <= max_j; ++j) {
            int odd_rem = freq[i] - j;
            if (odd_rem > odd || remain < i * j)
                continue;

            int max_possible_rem = (even - j + odd - odd_rem) * (i - 1);
            if (remain - i * j > max_possible_rem)
                continue;

            long long ways = comb[even][j] * comb[odd][odd_rem] % mod;
            ans = (ans + ways *
                             f(i - 1, even - j, odd - odd_rem, remain - i * j) %
                             mod) %
                  mod;
        }
        return dp[key] = ans;
    }

    int countBalancedPermutations(std::string& num) {
        freq.fill(0);
        sum = 0;
        n = num.size();
        for (char c : num) {
            int d = c - '0';
            freq[d]++;
            sum += d;
        }
        if (sum & 1)
            return 0;
        sum /= 2;

        int oddLen = n / 2, evenLen = n - oddLen;
        dp.clear();
        return f(9, evenLen, oddLen, sum);
    }
};

auto init = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
