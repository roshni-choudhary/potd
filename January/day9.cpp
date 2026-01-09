//865. Smallest Subtree with all the Deepest Nodes
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
class Solution {
public:
    map<TreeNode*, int> mp;
    set<TreeNode*> st;

    void maxdepth(TreeNode* root, int depth) {
        if (!root) return;
        mp[root] = depth;
        maxdepth(root->left, depth + 1);
        maxdepth(root->right, depth + 1);
    }

    TreeNode* lca(TreeNode* root) {
        if (!root) return NULL;
        if (st.count(root)) return root;

        TreeNode* l = lca(root->left);
        TreeNode* r = lca(root->right);

        if (l && r) return root;
        if (l) return l;
        if (r) return r;
        return NULL;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxdepth(root, 0);

        int maxd = 0;
        for (auto &[node, d] : mp)
            maxd = max(maxd, d);

        for (auto &[node, d] : mp)
            if (d == maxd)
                st.insert(node);

        return lca(root);
    }
};
time complexity:
Traversal-
DFS visits each node at most once → O(N)
Set lookup
st.count(root) is:
O(log N) if set
O(1) average if unordered_set
sc=map / set → O(N)
Recursion stack → O(H) (tree height)
*/
