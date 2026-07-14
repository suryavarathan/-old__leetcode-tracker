// Last updated: 7/14/2026, 3:20:01 PM
class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        if (n < 4) return false;

        int i = 0;

        // Phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        // invalid if no climb or reached end
        if (i == 0 || i == n - 1) return false;

        int j = i;

        // Phase 2: strictly decreasing
        while (j + 1 < n && nums[j] > nums[j + 1]) {
            j++;
        }

        // invalid if no drop or reached end
        if (j == i || j == n - 1) return false;

        // Phase 3: strictly increasing again
        while (j + 1 < n && nums[j] < nums[j + 1]) {
            j++;
        }

        // must end exactly at last index
        return j == n - 1;
    }
}