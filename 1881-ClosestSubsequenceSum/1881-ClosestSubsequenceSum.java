// Last updated: 7/14/2026, 3:27:49 PM
class Solution {
    public int minAbsDifference(int[] nums, int goal) {
        int n = nums.length;
        
        // Step 1: Split into two halves
        int[] a = Arrays.copyOfRange(nums, 0, n / 2);
        int[] b = Arrays.copyOfRange(nums, n / 2, n);
        
        // Step 2: Generate all subset sums for each half
        List<Integer> s1 = new ArrayList<>();
        List<Integer> s2 = new ArrayList<>();
        subset(a, s1, 0, 0);  // start with sum = 0 at index 0
        subset(b, s2, 0, 0);
        
        // Step 3: Sort second half's sums for binary search
        Collections.sort(s2);
        
        int ans = Integer.MAX_VALUE;
        
        // Step 4: For each sum in first half, find complement in second half
        for (int x : s1) {
            int target = goal - x;  // desired sum from second half
            
            // Binary search in s2 for value >= target
            int idx = lowerBound(s2, target);
            
            // Check element at idx (if exists)
            if (idx < s2.size()) {
                ans = Math.min(ans, Math.abs(x + s2.get(idx) - goal));
            }
            // Check element before idx (if exists)
            if (idx > 0) {
                ans = Math.min(ans, Math.abs(x + s2.get(idx - 1) - goal));
            }
            
            // Early exit if exact match found
            if (ans == 0) return 0;
        }
        
        return ans;
    }
    
    // Binary search: returns first index where element >= target
    private int lowerBound(List<Integer> list, int target) {
        int left = 0, right = list.size() - 1;
        int result = list.size();  // default if all elements < target
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
    
    // Generate all subset sums recursively
    private void subset(int[] nums, List<Integer> sums, int currentSum, int index) {
        if (index == nums.length) {
            sums.add(currentSum);
            return;
        }
        
        // Include nums[index]
        subset(nums, sums, currentSum + nums[index], index + 1);
        // Exclude nums[index]
        subset(nums, sums, currentSum, index + 1);
    }
}