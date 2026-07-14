// Last updated: 7/14/2026, 3:19:36 PM
class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            java.util.HashSet<Integer> odd = new java.util.HashSet<>();
            java.util.HashSet<Integer> even = new java.util.HashSet<>();

            for (int j = i; j < n; j++) {
                if ((nums[j] & 1) == 1)
                    odd.add(nums[j]);
                else
                    even.add(nums[j]);

                if (odd.size() == even.size())
                    maxi = Math.max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
}