# Last updated: 7/14/2026, 3:28:12 PM
import heapq
class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        heap = []
        for i, row in enumerate(matrix):
            for j, cell in enumerate(row):
                if i > 0:
                    cell ^= matrix[i-1][j]
                if j > 0:
                    cell ^= matrix[i][j-1]
                if i > 0 and j > 0:
                    cell ^= matrix[i-1][j-1]
                matrix[i][j] = cell
                heapq.heappush(heap, cell)
                if len(heap) > k: heapq.heappop(heap)
        return heap[0]