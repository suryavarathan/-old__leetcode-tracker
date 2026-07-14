// Last updated: 7/14/2026, 3:21:34 PM
class Solution {
    public boolean canBeEqual(String s1, String s2) {

        int[] even = new int[26];
        int[] odd = new int[26];

        for( int i = 0; i < 4; i++ ) {
            if( i % 2 == 0 ) {
                even[s1.charAt(i) - 'a'] += 1;
                even[s2.charAt(i) - 'a'] -= 1;
            }
            else{
                odd[s1.charAt(i) - 'a'] += 1;
                odd[s2.charAt(i) - 'a'] -= 1;
            }
        }

        for( int i = 0; i < 26; i++ ) {
            if( even[i] != 0 || odd[i] != 0 ) return false;
        }

        return true;
    }
}