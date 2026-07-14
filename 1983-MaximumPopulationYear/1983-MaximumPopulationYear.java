// Last updated: 7/14/2026, 3:25:35 PM
class Solution {
    public int maximumPopulation(int[][] logs) {
        int[]arr=new int[(2050-1950)+1];
        for(int []a:logs){
            int x=a[0];
            int y=a[1];
            arr[x-1950]++;
            arr[y-1950]--;
        }
        int max=arr[0];
        int ans=0;
        for(int i=1;i<(2050-1950)+1;i++){
            arr[i]=arr[i-1]+arr[i];
            if(max<arr[i]){
                max=arr[i];
                ans=i;
            }
        }
        return ans+1950;
    }
}