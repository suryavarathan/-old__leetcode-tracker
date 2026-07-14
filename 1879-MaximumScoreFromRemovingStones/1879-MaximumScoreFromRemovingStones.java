// Last updated: 7/14/2026, 3:27:53 PM
class Solution {
    public int maximumScore(int a, int b, int c) {
        //maxheap
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>((a1, b1) -> (b1 - a1));
        
        //store in maxHeap
        maxHeap.add(a);
        maxHeap.add(b);
        maxHeap.add(c);
        
        int score = 0;
        while(maxHeap.size() > 1){
            //find first two max number
            int maxNum1 = maxHeap.remove();
            int maxNum2 = maxHeap.remove();
            
            //decrement both 
            maxNum1--;
            maxNum2--;
            
            //only add in heap, if greater than 0
            if(maxNum1 > 0) maxHeap.add(maxNum1);
            if(maxNum2 > 0) maxHeap.add(maxNum2);
            
            //increase score
            score++;
        }
        
        return score;
    }
}