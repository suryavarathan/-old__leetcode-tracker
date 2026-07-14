// Last updated: 7/14/2026, 3:22:30 PM
class Solution {
    public String reversePrefix(String word, char ch) {
        int index = word.indexOf(ch);
        if(index == -1) return word ;

        char []arr = word.toCharArray();

        int left = 0 ;
        int right = index;
        while(left <= right){
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        
        return new String(arr);
    }
}