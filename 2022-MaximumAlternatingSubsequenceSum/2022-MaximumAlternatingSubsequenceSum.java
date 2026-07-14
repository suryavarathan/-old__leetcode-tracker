// Last updated: 7/14/2026, 3:24:46 PM
class Solution {
    int n;
    public long maxAlternatingSum(int[] nums) {
        n = nums.length;
        long[][] memo = new long[n][2];
        for( long[] row : memo ) {
            Arrays.fill( row, -1 );
        }
        
        return solve( nums, 0, true, memo );
    }
    private long solve( int[] nums, int idx, boolean isEven, long[][] memo ) {
        if( idx >= n ) {
            return 0; 
        }
      
        if( memo[idx][ isEven ? 0 : 1 ] != -1) {
            return memo[idx][ isEven ? 0 : 1 ];
        } 

        // long take = 0;
        long take = isEven ? nums[idx] : -nums[idx];
        take += solve( nums, idx + 1, !isEven, memo );

        long skip = solve( nums, idx + 1, isEven, memo );

        return memo[idx][ isEven ? 0 : 1 ] =  Math.max( take, skip );
    }
}