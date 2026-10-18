class Solution {
  inline static const int M = 1e9 + 7;
  inline static vector<long long> F = vector<long long>(1001);
  inline static vector<long long> Fi = vector<long long>(F.size());
  long long fme(long long b, long long e) {
    if (e == 0) return 1;
    if (e & 1) return b * fme(b, e - 1) % M;
    return fme(b * b % M, e >> 1);
  }
  struct Node {
    int size;
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr), size(-1) {}
    void insert(int v) {
      if (v > val)
        if (right == nullptr)
          right = new Node(v);
        else
          right->insert(v);
      else if (left == nullptr)
        left = new Node(v);
      else
        left->insert(v);
    }
    int getSize() {
      if (size != -1) return size;
      if (left == nullptr && right == nullptr) return 1;
      if (left == nullptr) return right->getSize() + 1;
      if (right == nullptr) return left->getSize() + 1;
      return left->getSize() + right->getSize() + 1;
    }
    long long getCombinations() {
      if (size == -1) size = getSize();
      if (size == 1) return 1;
      if (left == nullptr) return right->getCombinations();
      if (right == nullptr) return left->getCombinations();
      long long sl = left->getSize();
      long long sr = right->getSize();
      long long c = left->getCombinations() * right->getCombinations() % M;
      c = (c * F[size - 1]) % M;
      c = (c * Fi[sl]) % M;
      c = (c * Fi[sr]) % M;
      return c;
    }
  };

 public:
  Solution() {
    if (F[0] == 1) return;
    F[0] = 1;
    for (int i = 1; i < F.size(); i++) F[i] = F[i - 1] * i % M;
    Fi.back() = fme(F.back(), M - 2);
    for (int i = F.size() - 2; i >= 0; i--) Fi[i] = Fi[i + 1] * (i + 1) % M;
  }
  int numOfWays(vector<int>& nums) {
    Node n(nums[0]);
    for (int i = 1; i < nums.size(); i++) n.insert(nums[i]);
    return n.getCombinations() - 1;
  }
};