class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0 || size == 1)
            return;
        k = k % size;
        if (size < k)
            return;
        vector<int> store = nums;
        int j = size - k;
        for (int i = 0; i < size; i++) {
            if (j + i < size)
                nums[i] = store[j + i];
            else
                nums[i] = store[i - size + j];
        }
    }
};