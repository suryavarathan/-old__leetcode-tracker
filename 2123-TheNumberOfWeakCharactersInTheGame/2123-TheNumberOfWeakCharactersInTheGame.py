# Last updated: 7/14/2026, 3:22:32 PM
class Solution:
    def numberOfWeakCharacters(self, p: List[List[int]]) -> int:
        p.sort()
        maximums=[]
        mx=0
        for i in range(len(p)-1,-1,-1):
            mx=max(mx,p[i][1])
            maximums.append(mx)
        maximums=maximums[::-1] #reversing the array
        ans=0
        for i in range(len(p)):
            left=i
            right=len(p)
            while(left<right):
                mid=(left+right)//2
                if(p[mid][0]>p[i][0]):
                    right=mid
                else:
                    left=mid+1
            #the first position whose attack is greater than i's attack is right
            if(right<len(p) and maximums[right]>p[i][1]):
                ans+=1
        return ans