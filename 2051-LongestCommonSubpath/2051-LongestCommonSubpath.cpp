// Last updated: 7/14/2026, 3:24:01 PM
class Solution 
{
    public:
        bool isOk(int mid,vector<vector<int>>& paths)
        {
            //rabin karp double hashing logic
            if(!mid) return true;
            long long base1=100003,mod1=1e9+7;
            long long base2=100019,mod2=1e9+9;
            long long power1=1,power2=1;

            for(int i=0;i<mid-1;i++)
            {
                power1=(power1*base1)%mod1;
                power2=(power2*base2)%mod2;
            }
            unordered_set<unsigned long long>s;
            for(int i=0;i<paths.size();i++)
            {
                unordered_set<unsigned long long>st;
                long long h1=0,h2=0;
                for(int j=0;j<paths[i].size();j++)
                {
                    h1=(h1*base1+paths[i][j])%mod1;
                    h2=(h2*base2+paths[i][j])%mod2;
                    if(j>=mid-1)
                    {
                        unsigned long long combined=(unsigned long long)h1<<32|h2;
                        if(i==0)
                        {
                            st.insert(combined);
                        }
                        else if(s.count(combined))
                        {
                            st.insert(combined);
                        }
                        long long out1=(paths[i][j-mid+1]*power1)%mod1;
                        long long out2=(paths[i][j-mid+1]*power2)%mod2;

                        h1=(h1-out1+mod1)%mod1;
                        h2=(h2-out2+mod2)%mod2;
                    }
                }
                s=st;
                if(s.empty()) return false;
            }
            return true;
        }
        int longestCommonSubpath(int n, vector<vector<int>>& paths) 
        {       
            int l=0;
            int ans=0;
            int h=INT_MAX;
            for(auto it:paths)
            {
                h=min(h,(int)it.size());
            }
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if(isOk(mid,paths))
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    h=mid-1;
                }
            }
            return ans;
        }
};