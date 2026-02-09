//1382. Balance a Binary Search Tree
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
vector<int> arr;
void dfs(TreeNode* root)
{
    if(root==nullptr) return;
    dfs(root->left);
    arr.push_back(root->val);
    dfs(root->right);
}
TreeNode* build(int l,int h)
{
 if(l>h) return nullptr;
 int mid=l+(h-l)/2;
 TreeNode* r=new TreeNode(arr[mid]);
 r->left=build(l,mid-1);
 r->right=build(mid+1,h);
 return r;
}
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return build(0,arr.size()-1);
    }
};
 */