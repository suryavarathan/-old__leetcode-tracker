# Last updated: 7/14/2026, 3:20:30 PM
class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(edges) + 1

        adj = [[] for _ in range(n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        depth = [0] * (n + 1)
        parent = [0] * (n + 1)
        visited = [0] * (n + 1)
        visited[1] = 1
        q = deque([1])
        while q:
            node = q.popleft()
            for nei in adj[node]:
                if not visited[nei]:
                    visited[nei] = 1
                    depth[nei] = depth[node] + 1
                    parent[nei] = node
                    q.append(nei)

        LOG = max(1, n.bit_length())
        up = [parent]
        for k in range(1, LOG):
            prev = up[-1]
            up.append([prev[prev[v]] for v in range(n + 1)])

        def lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u
            diff = depth[u] - depth[v]
            for k in range(LOG):
                if (diff >> k) & 1:
                    u = up[k][u]
            if u == v:
                return u
            for k in range(LOG - 1, -1, -1):
                if up[k][u] != up[k][v]:
                    u = up[k][u]
                    v = up[k][v]
            return up[0][u]

        pow2 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow2[i] = pow2[i - 1] * 2 % MOD

        ans = []
        for u, v in queries:
            k = depth[u] + depth[v] - 2 * depth[lca(u, v)]
            ans.append(pow2[k - 1] if k else 0)
        return ans