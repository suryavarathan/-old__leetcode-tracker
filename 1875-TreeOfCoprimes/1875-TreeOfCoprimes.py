# Last updated: 7/14/2026, 3:27:59 PM
class Solution:
    def getCoprimes(self, nums: List[int], edges: List[List[int]]) -> List[int]:
        
        @functools.lru_cache(None)
        def find_ancestor(node, node_value):
            '''Returns the closest ancestor with a GCD of 1 if one exists.  Otherwise return -1.'''
            if node == -1:
                return -1
            parent = parent_graph[node]
            if math.gcd(node_value, nums[parent]) == 1:
                return parent
            return find_ancestor(parent, node_value)
        
        # Convert edges to a graph
        graph = collections.defaultdict(set)
        for a, b in edges:
            graph[a].add(b)
            graph[b].add(a)
        
        # Find the parent of each node
        parent_graph = collections.defaultdict(int)
        q = [(0, -1)]
        while q:
            next_level = []
            for node, parent in q:
                parent_graph[node] = parent
                for neigh in graph[node]:
                    if neigh != parent:
                        next_level.append((neigh, node))
            q = next_level
        
        # Find the nearest ancestor for each node that has a GCD of 1
        return [find_ancestor(node, nums[node]) for node in range(len(nums))]