# Last updated: 7/14/2026, 3:27:44 PM
class Solution: 
    def countHomogenous(self, s: str) -> int:

        grp = [len(list(homog)) for _, homog in groupby(s)]
        
        return sum(map(lambda x: x*(x+1), grp))//2 %1_000_000_007