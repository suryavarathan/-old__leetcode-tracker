// Last updated: 7/14/2026, 3:19:55 PM
class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        
        int n = landDuration.length;
        int m = waterDuration.length;
        int l = Integer.MAX_VALUE;
        int w = Integer.MAX_VALUE;
        for(int i = 0 ; i < n ;i++){
            l=Math.min(l,landStartTime[i]+landDuration[i]);
        }
        for(int i = 0 ; i < m ;i++){
            w=Math.min(w,waterStartTime[i]+waterDuration[i]);
        }
        int ans = Integer.MAX_VALUE;
        for(int i = 0 ; i < n ;i++){
            ans=Math.min(ans, Math.max(w,landStartTime[i]) + landDuration[i]);
        }
        for(int i = 0 ; i < m ;i++){
            ans=Math.min(ans, Math.max(l,waterStartTime[i]) + waterDuration[i]);
        }
        return ans;
    }
}