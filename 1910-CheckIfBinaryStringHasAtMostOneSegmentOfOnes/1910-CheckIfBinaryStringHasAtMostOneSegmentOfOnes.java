// Last updated: 7/14/2026, 3:27:06 PM
class Solution {
    public boolean checkOnesSegment(String s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='1' && count>0) return false;
            else if(s.charAt(i)=='0') count++;
        }
        return true;
    }
}