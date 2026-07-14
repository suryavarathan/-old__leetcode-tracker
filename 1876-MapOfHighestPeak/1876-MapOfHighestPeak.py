# Last updated: 7/14/2026, 3:27:57 PM
from collections import deque

class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        R, C = len(isWater), len(isWater[0])
        # Initialize the manifold with a 'null' potential
        res = [[-1] * C for _ in range(R)]
        queue = deque()
        
        # Set Boundary Conditions: Water cells are the 'source' (Height = 0)
        for r in range(R):
            for c in range(C):
                if isWater[r][c] == 1:
                    res[r][c] = 0
                    queue.append((r, c))
        
        # Wavefront Propagation: 
        # This is essentially a discrete 'Distance Transform'
        while queue:
            r, c = queue.popleft()
            
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nr, nc = r + dr, c + dc
                
                # If the cell is within bounds and not yet part of the manifold
                if 0 <= nr < R and 0 <= nc < C and res[nr][nc] == -1:
                    # The height is constrained by the unit gradient property
                    res[nr][nc] = res[r][c] + 1
                    queue.append((nr, nc))
                    
        return res        