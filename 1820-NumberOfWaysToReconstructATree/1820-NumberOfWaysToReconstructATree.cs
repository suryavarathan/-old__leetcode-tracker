// Last updated: 7/14/2026, 3:28:53 PM
public class Solution {
    public int CheckWays(int[][] pairs) {
        var adj = new Dictionary<int, HashSet<int>>();
        foreach (var p in pairs) {
            int u = p[0], v = p[1];
            if (!adj.ContainsKey(u)) adj[u] = new HashSet<int>();
            if (!adj.ContainsKey(v)) adj[v] = new HashSet<int>();
            adj[u].Add(v);
            adj[v].Add(u);
        }

        int n = adj.Count;
        // Step 2: find root candidate
        int root = -1;
        foreach (var kv in adj) {
            if (kv.Value.Count == n - 1) {
                root = kv.Key;
                break;
            }
        }
        if (root == -1) return 0;

        int res = 1;
        foreach (var kv in adj) {
            int u = kv.Key;
            if (u == root) continue;

            int parent = -1;
            int parentDegree = int.MaxValue;
            foreach (var v in adj[u]) {
                if (adj[v].Count >= adj[u].Count) {
                    if (adj[v].Count < parentDegree) {
                        parentDegree = adj[v].Count;
                        parent = v;
                    }
                }
            }
            if (parent == -1) return 0;

            // Check adjacency consistency
            foreach (var nei in adj[u]) {
                if (nei == parent) continue;
                if (!adj[parent].Contains(nei)) return 0;
            }

            if (adj[parent].Count == adj[u].Count) res = 2;
        }

        return res;
    }
}