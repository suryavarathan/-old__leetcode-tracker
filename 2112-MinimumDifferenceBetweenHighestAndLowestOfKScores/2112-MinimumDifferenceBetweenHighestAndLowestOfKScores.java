// Last updated: 7/14/2026, 3:22:42 PM
class Solution {
    public int minimumDifference(int[] nums, int k) {
        if (k == 1) return 0;
        Arrays.sort(nums);
        int i=0,j=k-1,n=nums.length,mini=Integer.MAX_VALUE;
        while(j<n){
            int diff=nums[j]-nums[i];
            mini=Math.min(mini,diff);
            i++;
            j++;
        }
        return mini;
    }
}
