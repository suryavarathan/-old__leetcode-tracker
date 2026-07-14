// Last updated: 7/14/2026, 3:26:32 PM
class Solution {
    struct Node {
        vector<int> tr, bl;
        int cnt;
    };

    void merge(vector<Node> &nodes, int m, int i) {
        if (i == -1) return;
        nodes[m].tr[0] = max(nodes[m].tr[0], nodes[i].tr[0]);
        nodes[m].tr[1] = max(nodes[m].tr[1], nodes[i].tr[1]);
        nodes[m].bl[0] = min(nodes[m].bl[0], nodes[i].bl[0]);
        nodes[m].bl[1] = min(nodes[m].bl[1], nodes[i].bl[1]);
        nodes[m].cnt += nodes[i].cnt;
    }
    
    inline bool isPointInside(const vector<int> &p, const vector<int> &c) {
        return (p[0] - c[0]) * (p[0] - c[0]) + (p[1] - c[1]) * (p[1] - c[1]) <= c[2] * c[2];
    }
    bool circleContains(const vector<int> &q, const Node& node) {
        return isPointInside(node.bl, q) && isPointInside(node.tr, q)
            && isPointInside({node.bl[0], node.tr[1]}, q)
            && isPointInside({node.tr[0], node.bl[1]}, q);
    }
    
    bool circleIntersects(const vector<int> &q, const Node& node) {
        int cx = clamp(q[0], node.bl[0], node.tr[0]) - q[0];
        int cy = clamp(q[1], node.bl[1], node.tr[1]) - q[1];
        
        return cx*cx + cy * cy <= q[2] * q[2];
    }

    int buildTree(vector<vector<int>>& p, vector<Node>& nodes, int depth, int i, int j) {
        if (j == i) return -1;
        else if (j - i == 1) {
            nodes[i] = { p[i], p[i], 1 };
            return i;
        }

        int k = 1 - depth & 1, m = i + (j - i) / 2;
        nth_element(p.begin() + i, p.begin() + m, p.begin() + j,
            [k](auto& a, auto& b) { return a[k] < b[k]; });
        nodes[m] = { p[m], p[m], 1 };

        merge(nodes, m, buildTree(p, nodes, depth + 1, i, m));
        merge(nodes, m, buildTree(p, nodes, depth + 1, m + 1, j));
        return m;
    }
    
    int pointsInside(const vector<vector<int>> &t, const vector<Node> &nodes,
                     const vector<int> &q, int depth,
                    int i, int j) {
        if (j == i) return 0;
        else if (j - i == 1) return isPointInside(t[i], q);

        int m = i + (j - i) / 2;
        if (circleContains(q, nodes[m])) return nodes[m].cnt;
        else if (!circleIntersects(q, nodes[m])) return 0;
        else {
            int k = 1 - depth & 1, diff = t[m][k] -  q[k];
            if (diff > q[2]) return pointsInside(t, nodes, q, depth+1, i, m);
            else if (diff < -q[2]) return pointsInside(t, nodes, q, depth+1, m+1, j);
            else
                return pointsInside(t, nodes, q, depth+1, i, m)
                    + isPointInside(t[m], q)
                    + pointsInside(t, nodes, q, depth+1, m+1, j);
        }
    }
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<Node> nodes(points.size());
        buildTree(points, nodes, 0, 0, points.size());

        vector<int> res(queries.size());
        for (size_t i = 0; i < queries.size(); ++i)
            res[i] = pointsInside(points, nodes, queries[i], 0, 0, points.size());
        return res;
    }
};