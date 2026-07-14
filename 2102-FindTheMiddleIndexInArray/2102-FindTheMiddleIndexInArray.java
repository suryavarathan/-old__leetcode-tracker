// Last updated: 7/14/2026, 3:22:58 PM
class Solution {
    public int findMiddleIndex(int[] nums) {
        int n = nums.length;

        int total = 0;
        for(int x : nums) {
            total += x;
        } 

        int bef = 0;
        int aft = total;

        for(int i=0; i<n; i++) {
            aft = aft - nums[i];
            if(bef == aft) return i;
            bef = bef + nums[i];
        }

        return -1;
    }
}