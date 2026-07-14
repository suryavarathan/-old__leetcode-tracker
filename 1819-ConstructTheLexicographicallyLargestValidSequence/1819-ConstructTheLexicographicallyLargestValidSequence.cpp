// Last updated: 7/14/2026, 3:28:56 PM
class Solution {
    int allMarked{};  // Bitmask representing all numbers being placed
    std::vector<int> res;  // Stores the final valid sequence

    // Checks if all remaining numbers can still be placed in the sequence.
    bool allNumbersCanStillBePlaced(int n, int mask, int index) {
        for (int i = n; i > 1; --i) {  // Only check numbers greater than 1
            if ((mask & (1 << i)) == 0 && index + i >= 2 * n) return false;
        }
        return true;
    }

    // Backtracking function to construct the sequence.
    bool dfs(std::vector<int>& nums, int total, int n, int currIndex, int& mask) {        
        if (total == 0) {  // If all numbers are placed, store result
            res = nums;
            return true;
        }

        if (mask == allMarked) return false;  // Stop if all numbers are used
        if (!allNumbersCanStillBePlaced(n, mask, currIndex)) return false;  // Prune invalid branches

        // If current position is already filled, move to the next position
        if (nums[currIndex] != -1) {
            return dfs(nums, total, n, currIndex + 1, mask);
        }

        // Try placing numbers from largest to smallest for lexicographical order
        for (int i = n; i >= 1; --i) {
            if ((mask & (1 << i)) == 0 && nums[currIndex] == -1) {  // If i is not placed yet
                if (i == 1) {  // Special case: 1 only appears once
                    nums[currIndex] = 1;
                    mask |= (1 << i);
                    if (dfs(nums, total - 1, n, currIndex + 1, mask)) return true;
                    mask ^= (1 << i);
                    nums[currIndex] = -1;
                } else if (currIndex + i < 2 * n - 1 && nums[currIndex + i] == -1) {  // Place both occurrences
                    nums[currIndex] = nums[currIndex + i] = i;
                    mask |= (1 << i);
                    if (dfs(nums, total - 2, n, currIndex + 1, mask)) return true;
                    mask ^= (1 << i);
                    nums[currIndex] = nums[currIndex + i] = -1;
                }
            }
        }

        return false;
    }

public:
    // Constructs the lexicographically largest valid sequence.
    vector<int> constructDistancedSequence(int n) {
        std::vector<int> nums(2 * n - 1, -1);  // Initialize sequence with -1 (empty slots)

        allMarked = (1 << (n + 1)) - 1;  // Bitmask where all numbers are marked
        allMarked ^= 1;  // Exclude 0 (not used in the sequence)

        int mask{};  // Tracks used numbers
        dfs(nums, 2 * n - 1, n, 0, mask);  // Start backtracking

        return res;
    }
};