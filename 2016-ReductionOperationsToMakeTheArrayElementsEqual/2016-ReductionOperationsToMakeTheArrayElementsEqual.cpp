// Last updated: 7/14/2026, 3:24:54 PM
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        int sum = 0;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] != nums[i]) {
                sum += n - i;
            }
        }
        return sum;
    }
};