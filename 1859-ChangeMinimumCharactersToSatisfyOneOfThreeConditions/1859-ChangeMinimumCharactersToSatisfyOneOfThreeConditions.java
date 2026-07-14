// Last updated: 7/14/2026, 3:28:13 PM
class Solution {
    public int minCharacters(String a, String b) {
        
         int lengthA = a.length();
         int lengthB = b.length();
         int[] afreq = new int[26];
         int[] bfreq = new int[26];
     
        
         int maxFreqA = 0;
         int maxFreqB = 0;

         int res = Integer.MAX_VALUE;
        
         for( int i = 0 ; i < a.length(); i++ )
         {
            int index = a.charAt(i) -'a';
            afreq[ index ]++;    
            maxFreqA = Math.max( maxFreqA,afreq[ index ]); 
         }
        
      
          for( int i = 0 ; i < b.length(); i++ )
          {
              int index = b.charAt(i) -'a';
              bfreq[ index ]++;    
              maxFreqB = Math.max( maxFreqB,bfreq[ index ]); 
          }
        
        res = Math.min( res, lengthA + lengthB - maxFreqA - maxFreqB ); // Both a and b consist of only one distinct letter.
        
        for( int i = 1; i < 26; i++ )
        {
             afreq[i] = afreq[i] + afreq[i-1]; // A prefixSum 
             bfreq[i] = bfreq[i] + bfreq[i-1];// B prefixSum
        }   
        
		//Loop only goes till 'y' character because there is no character greater than z. 
        for( int i =0 ; i < 25; i++ )
        {
            res = Math.min( lengthA - afreq[i] + bfreq[i],res  );
            res = Math.min( lengthB - bfreq[i] + afreq[i],res  );
        }
    return res;
    }
}



