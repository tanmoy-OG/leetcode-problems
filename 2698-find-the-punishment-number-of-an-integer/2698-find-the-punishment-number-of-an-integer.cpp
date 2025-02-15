#include <iostream>
#include <string>

class Solution {
public:
    int punishmentNumber(int n) {
        int totalSum = 0;

        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (canPartition(std::to_string(square), i)) {
                totalSum += square;
            }
        }

        return totalSum;
    }

private:
    bool canPartition(const std::string& numStr, int target) {
        return backtrack(numStr, target, 0, 0);
    }

    bool backtrack(const std::string& numStr, int target, int start,
                   int currentSum) {
        if (currentSum > target)
            return false;
        if (start == numStr.length())
            return currentSum == target;

        for (int end = start + 1; end <= numStr.length(); end++) {
            std::string partStr = numStr.substr(start, end - start);
            int part = std::stoi(partStr);
            if (backtrack(numStr, target, end, currentSum + part)) {
                return true;
            }
        }
        return false;
    }
};
