// Last updated: 7/14/2026, 3:24:14 PM
class Solution {
    public int maxProductDifference(int[] nums) {
        int n = nums.length;
        int minE_1 = Integer.MAX_VALUE;
        int minE_2 = Integer.MAX_VALUE;
        int maxE_1 = Integer.MIN_VALUE;
        int maxE_2 = Integer.MIN_VALUE;

        for(int num : nums){
            // Find max two values...
            if(num > maxE_1){
                maxE_2 = maxE_1;
                maxE_1 = num;
            } else if(num > maxE_2 && num <= maxE_1){
                maxE_2 = num;
            }

            // FInd min two values...
            if(num < minE_1){
                minE_2 = minE_1;
                minE_1 = num;
            } else if(num < minE_2 && num >= minE_1){
                minE_2 = num;
            }
        }

        return (maxE_1*maxE_2) - (minE_1*minE_2);
    }
}



// class Solution {
//     public int maxProductDifference(int[] nums) {
//         int n = nums.length;
//         Arrays.sort(nums);
//         return (nums[n-1]*nums[n-2]) - (nums[0]*nums[1]);
//     }
// }