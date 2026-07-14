// Last updated: 7/14/2026, 3:28:24 PM
class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        int[] arr = new int[46];          // the highest value of highLimit was 100000 meaning max box no could be when HL is 99999 => 9+9+9+9+9 = 45 and since 1 indexed array is used in this solution , 46 is taken as the size.
        int max = 0;
        for(int i = lowLimit; i <= highLimit; i++){
            int temp = i;
            int box = 0;
            while(temp > 0){            // To get the single digits to add one by one.
                box += temp %  10;
                temp /= 10;
            }
            arr[box]++;
            if(arr[box] > max){
                max = arr[box];
            }
        }
        
        return max;
    }
}