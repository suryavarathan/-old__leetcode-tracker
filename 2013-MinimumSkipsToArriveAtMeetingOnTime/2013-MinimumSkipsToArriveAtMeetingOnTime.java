// Last updated: 7/14/2026, 3:24:58 PM
class Solution {
    
    public double dfs(int[] dist, int speed, int skips) {
        double[][] dp = new double[dist.length][skips+1];
        double eps = 1e-9;
        for(int i = 0; i <= skips; i++) {
            dp[0][i] = dist[0]*1.0/(speed) - eps;
        }
        
        for(int i = 1; i < dist.length; i++) {
            dp[i][0] =Math.ceil(dp[i-1][0]) + dist[i]*1.0/(speed) - eps;
            for(int j = 1; j <= skips; j++) {
                double time = dp[i-1][j-1] + dist[i]*1.0/(speed) - eps;
                dp[i][j] = Math.min(time, Math.ceil(dp[i-1][j]) + dist[i]*1.0/(speed)-eps);
            }
        }
        return dp[dist.length-1][skips];
    }
    public int minSkips(int[] dist, int speed, int hoursBefore) {        
        int left = 0;
        int right = dist.length;
        
        while(left < right) {
            int mid = (left) + (right - left)/2;
            if(dfs(dist, speed, mid) > 1.0*hoursBefore) {
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        return dfs(dist, speed, left) <= 1.0*hoursBefore ? left : -1;
    }
}