// Last updated: 7/14/2026, 3:22:28 PM
class Solution {
    public int firstDayBeenInAllRooms(int[] nv) {
        int len = nv.length;
        long[] dp = new long[len];
        dp[1] = 2;
        int mod = 1000000007;
        for(int i = 2 ; i < len ; i++){
            dp[i] = dp[i-1] + dp[i-1] + mod - dp[nv[i-1]] + 2;
            dp[i] %= mod;
        }
        return (int)dp[len-1];
    }
}