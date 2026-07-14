# Last updated: 7/14/2026, 3:24:03 PM
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        return pow(5,(n+1)//2,m:=10**9+7)*pow(4,n//2,m)%m