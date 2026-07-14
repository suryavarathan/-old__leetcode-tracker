// Last updated: 7/14/2026, 3:29:35 PM
class Solution {
    public int maximumWealth(int[][] accounts) {
     int max=0;
     int sum=0;
        for(int i=0;i<accounts.length;i++){
            max=sum;
            sum=0;
            for(int j=0;j<accounts[i].length;j++){
               sum+=accounts[i][j];
            }
            sum=Math.max(sum,max);
        }
        return sum;
    }
    }