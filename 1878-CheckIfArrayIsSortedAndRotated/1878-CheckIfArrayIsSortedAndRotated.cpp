// Last updated: 7/14/2026, 3:27:54 PM
class Solution{
public:
    bool check(vector<int>& nums) {
        // just see the number of times we encounter a decreasing pair of adjacent elements in the array
        // it must be <= 1 because the pivot of the array is only such point in the array where we can get decreasing order
        // we did <= 1 instead of == 1 because if all elements are same so no pivot will be found.
        // so <= 1 is a safer check
        // also we include the comparison of the first and the last elment to ensure that if the array is sorted only but not rotated.
        int n = nums.size(),count = 0;
        for (int i = 1; i < n; i++){
            if (nums[i - 1] > nums[i]) count++;
        }
        if (nums[n - 1] > nums[0]) count++;
        return count <= 1;
    }
};