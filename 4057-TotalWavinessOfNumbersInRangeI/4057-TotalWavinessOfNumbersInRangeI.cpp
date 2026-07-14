// Last updated: 7/14/2026, 3:19:30 PM
class Solution {
public:
    int totalWaviness(int num1, int num2) { 
        int ans=0;
        for(int i=num1;i<=num2;i++){
            if(i/100==0) continue;   //For 2 digit-number or less.
            int temp=i;
            bool Lflag=false;
            bool Hflag=false;
            int PrevVal=temp%10;
            temp/=10;
            while(temp>0){
                int currVal=temp%10;
                if(currVal<PrevVal){ 
   
                    if(Hflag){      //Low-High-Low 
                        ans++;      //Wave-Peak
                    }

                    //Valley Might Occur in next iter.
                    Hflag=false;
                    Lflag=true;     // (Unknown)-Low-High
                }
                else if(currVal>PrevVal){    
  
                    if(Lflag){      //High-Low-High
                        ans++;      // Wave-Valley
                    }

                    //Peak Might Occur in next iter.
                    Lflag=false;
                    Hflag=true;     // (Unknown)-High-Low
                }
                else{
                    //(Unknown)-Equal-Equal {No Wave will occur in next iter.}
                    Lflag=false;
                    Hflag=false;
                }
                PrevVal=currVal;
                temp/=10;
            }
        }  
        return ans; 
    }
};