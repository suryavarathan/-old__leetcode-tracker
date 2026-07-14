// Last updated: 7/14/2026, 3:22:04 PM
class Solution {
    TreeNode* buildBinaryTree(int parentNode, map<int, vector<int>>& nodes) {
        if (nodes.find(parentNode) == nodes.end()) {
            return new TreeNode(parentNode);
        }
        
        TreeNode *leftTree, *rightTree;
        if (nodes[parentNode][0] == -1) leftTree = nullptr;
        else leftTree = buildBinaryTree(nodes[parentNode][0], nodes);

        if (nodes[parentNode][1] == -1) rightTree = nullptr;
        else rightTree = buildBinaryTree(nodes[parentNode][1], nodes);

        return new TreeNode(parentNode, leftTree, rightTree);
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, vector<int>> nodes;
        set<int> parentNodes, childNodes;
        int rootNode = -1;
        for (int i = 0; i < descriptions.size(); i++) {
            parentNodes.insert(descriptions[i][0]);
            childNodes.insert(descriptions[i][1]);
            if(nodes.find(descriptions[i][0]) != nodes.end()) {
                if (descriptions[i][2]) nodes[descriptions[i][0]][0] = descriptions[i][1];
                else nodes[descriptions[i][0]][1] = descriptions[i][1];
            } else {
                vector<int> value(2, -1);
                if (descriptions[i][2]) value[0] = descriptions[i][1];
                else value[1] = descriptions[i][1];
                nodes[descriptions[i][0]] = value;
            }
        }
        for (const auto& val: parentNodes) {
            if (childNodes.find(val) == childNodes.end()) {
                rootNode = val;
                break;
            }
        }
        return buildBinaryTree(rootNode, nodes);
    }
};