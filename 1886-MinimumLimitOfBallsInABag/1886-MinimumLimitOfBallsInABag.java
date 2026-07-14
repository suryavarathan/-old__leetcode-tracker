// Last updated: 7/14/2026, 3:27:42 PM
class Solution {
    public int minimumSize(int[] arr, int maxOperations) {
        int n = arr.length;
        int mx = Integer.MIN_VALUE;

        for(int i = 0 ; i < n ; i++){
            mx = Math.max(mx , arr[i]);
        }

        int lo = 1;
        int hi = mx;

        int ans = 1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(isPossible(arr , mid , maxOperations)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        return ans;
    }

    public boolean isPossible(int[] arr , int mid , int maxOperations){
        long operation = 0;

        int[] brr = new int[arr.length];

        for(int i = 0 ; i < arr.length ; i++){
            brr[i] = arr[i];
        }

        int i = 0;
        while(i < brr.length){
            if(brr[i] > mid){
                if(brr[i] % mid == 0) operation += (brr[i] / mid) - 1;
                else operation += brr[i] / mid;
            }

            i++;
        }

        if(operation > maxOperations) return false;
        else return true;
    }
}