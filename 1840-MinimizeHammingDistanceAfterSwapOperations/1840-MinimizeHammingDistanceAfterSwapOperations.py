# Last updated: 7/14/2026, 3:28:27 PM
from collections import deque 
class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        d={i:[] for i in range(n)}
        q=deque()
        for i,j in allowedSwaps:
            d[i].append(j)
            d[j].append(i)
        v=[False]*n
        def bfs(i):
            c=[]
            q = deque([i])
            while q:
                a = q.popleft()
                if v[a]:
                    continue
                c.append(a)
                v[a] = True
                for j in d[a]:   
                    if not v[j]:
                        q.append(j)
            return c
        r=[]
        for i in range(n):
            if not v[i]:
                r.append(bfs(i))
        #print(r)
        a=0
        for i in r:
            f={}
            t={}
            for j in i:
                f[source[j]]=f.get(source[j],0)+1
                t[target[j]]=t.get(target[j],0)+1
            for p in f:
                if p in t:
                    m=min(t[p],f[p])
                    t[p]-=m;f[p]-=m
            for _,k in f.items():  
                a+=k
        return a


        
        
                    