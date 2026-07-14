# Last updated: 7/14/2026, 3:24:38 PM
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        zeros = []
        ones = []
        twos = []
        for trip in triplets :
            if trip[0] > target[0] or trip[1] > target[1] or trip[2] > target[2] :
                continue
            zeros.append(trip[0])
            ones.append(trip[1])
            twos.append(trip[2])
            
        if target[0] in zeros and target[1] in ones and target[2] in twos:
            return True
        return False
