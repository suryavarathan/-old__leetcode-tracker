// Last updated: 7/14/2026, 3:21:33 PM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count = 0 ;
        int unknown = 0 ;

        for(int i=0 ; i<moves.size() ; i++) {
            if(moves[i]=='_'){
                unknown++ ;
                
            }
            if(moves[i]=='L') {
                count-- ;               
                          }

            if(moves[i]=='R') {
                count++ ;
            }

            
        }
        return abs(count )+unknown ;
    }
};