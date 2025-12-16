class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid = (start + end) / 2,
            index = 0;
        while (start <= end) {
            if (nums[mid] < target) {
                index = mid + 1;
                start = mid + 1;
            } else if (nums[mid] > target) {
                index = mid;
                end = mid - 1;
            } else
                return mid;
            mid = (start + end) / 2;
        }
        return index;
    }
};