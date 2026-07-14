// Last updated: 7/14/2026, 3:29:39 PM
class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) 
    {
        int n = nums.length;
        int[] pre = new int[n];
        int[] suf = new int[n];
        
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + nums[i];
            suf[n - i - 1] = suf[n - i] + nums[n - i - 1];
        }

        int[] ans = new int[n];

        for(int i = 0; i < n; i++)
        {
            ans[i] = Math.abs((nums[i] * (i + 1)) - pre[i]) + Math.abs((nums[i] * (n - i)) - suf[i]);
        }

        return ans;
    }
}