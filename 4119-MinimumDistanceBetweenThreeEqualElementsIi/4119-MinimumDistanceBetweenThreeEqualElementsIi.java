// Last updated: 7/14/2026, 3:19:24 PM
class Solution {
    public int minimumDistance(int[] nums) {
        /*
            <---- Key Idea ---->
            0.   Store elements , index to HashMap: Element = key, index = value.
            1.   Key = target = nums[i].
            2.   The place where values present greater than or equals to 3, store find distance.
            3.   distance = abs(i - j) + abs(j - k) + abs(k - i).
            4.   Take minimum of each index and store it in minDistance each time.
            5.   At the end just return the minDistance.
            
            Note:   distance = (j-i) + (k-j) + (k-i) == 2*(k-i); 
                    so we can use this directly.
        */
        int n = nums.length;

        if(n < 3) return -1;
        
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            List<Integer> list = map.getOrDefault(nums[i], new ArrayList<>());
            list.add(i);
            map.put(nums[i], list);
        }
        
        boolean pairFound = false;
        int minDistance = Integer.MAX_VALUE;
        for(int key : map.keySet()){
            List<Integer> list = map.get(key);
            int listSize = list.size();
            if(listSize >= 3){
                pairFound = true;
                for(int index = 0; index < listSize - 2; index++){
                    int i = list.get(index);
                    int k = list.get(index+2);
                    
                    int distance = 2*(k-i);
                    minDistance = Math.min(minDistance, distance);
                }
            } 
        }
        return pairFound ? minDistance : -1;
    }
}
