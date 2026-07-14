// Last updated: 7/14/2026, 3:21:11 PM
class Solution {
public:
    struct tnode{
        tnode* ptr[10];
        tnode(){
            for(int i=0;i<10;i++) ptr[i]=NULL;
        }

    };
    void insert(tnode* &t,string num,int i){
        if(i==num.size()) return;
        else{
            int idx=num[i]-'0';
            if(t->ptr[idx]==NULL) t->ptr[idx]=new tnode();
            insert(t->ptr[idx],num,i+1);
        } 
    }
    int val(tnode* &t,string num,int i){
        if(i==num.size()) return i;
        int idx=num[i]-'0';
        if(t->ptr[idx]!=NULL) return val(t->ptr[idx],num,i+1);
        return i;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        tnode* t=new tnode();
        for(int i=0;i<arr1.size();i++) insert(t,to_string(arr1[i]),0);
        int ans=0;
        for(int i=0;i<arr2.size();i++) ans=max(ans,val(t,to_string(arr2[i]),0));
        return ans;
    }
};
