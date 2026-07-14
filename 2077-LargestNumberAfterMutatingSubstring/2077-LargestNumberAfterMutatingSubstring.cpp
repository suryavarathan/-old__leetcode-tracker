// Last updated: 7/14/2026, 3:23:37 PM
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        
        bool hasMutationStarted = false;
        //we greedily mutate largest place valued digits (so, move from left to right)
        //But once our mutation chain breaks, we break the loop (explained above)
        for(char &ch : num) {
            int v = ch-'0';
            if(v > change[v] && hasMutationStarted) {
                break;
            }
			
            ch = max(v, change[v]) + '0';
            hasMutationStarted |= (v < change[v]);
        }
        
        return num;
    }
};