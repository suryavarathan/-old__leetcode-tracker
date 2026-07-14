# Last updated: 7/14/2026, 3:28:47 PM
class Trie:
    def __init__(self):
        self.tree = {}   
        self.bits = 31
    
    # adds binary representation of a number to trie
    def add(self,value):
        node = self.tree
        for i in range(self.bits,-1,-1):
            bit = 1 if (1<<i) & value else 0
            if bit not in node : node[bit] = {}
            node = node[bit]
        return 

    # finda max Xor of 'value' with every number present in trie
    def findMax(self,value):
        if not self.tree : return -1   
        node = self.tree
        maxXor = 0
        for i in range(self.bits,-1,-1):
            bit = 1 if (1<<i) & value else 0
            req = 1-bit
            if req in node:
                maxXor |= (1<<i)
                node = node[req]
            else:
                node = node[bit]
        return maxXor

class Solution:
    def maximizeXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        
        ln = len(nums)
        trie = Trie()

        nums.sort()
        queries = [ [i[0],i[1],ind] for ind,i in enumerate(queries)]
        queries.sort(key = lambda x : x[1])

        res = [-1] * len(queries)
        
        ind = 0
        for x,maxValue,i in queries:
            while ind < ln and nums[ind] <= maxValue:
                trie.add(nums[ind])
                ind += 1
            res[i] = trie.findMax(x)

        return res