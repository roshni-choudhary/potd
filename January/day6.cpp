//1161. Maximum Level Sum of a Binary Tree
#include<bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
 vector<long long> lsum;
        void dfs(TreeNode* node,int level)
        {
            if(node==nullptr)
            return;
            //level does not exist yet
            if(level==lsum.size())
            lsum.push_back(0);
            lsum[level]+=node->val;
            dfs(node->left,level+1);
            dfs(node->right,level+1);
        }
    int maxLevelSum(TreeNode* root) {
        lsum.push_back(0);
        dfs(root,1);
        int n=lsum.size();
        long long maxs=INT_MIN,ans;
        for(int i=1;i<n;i++)
        {
            if(lsum[i]>maxs)
            { maxs=lsum[i];
            ans=i;
            }
        }
        return ans;
    }
};
//tc
// O(n)
// Where n = number of nodes in the binary tree.
//sc
// O(h + L)
// Where:
// h = height of the tree (recursion stack)
// L = number of levels in the tree (levelSum.size())
// and for L=levelSum vector → O(L)
// So:
// skewed tree → O(n)
// balanced tree → O(log n)

//bfs approach
 int maxLevelSum(TreeNode* root) {
       queue<TreeNode*> q;
       q.push(root);
       int level=1,ans=1,maxsum=INT_MIN;
       while(!q.empty())
       {
       int sz=q.size();
       int csum=0;
       //traverse one level
       for(int i=0;i<sz;i++){
       TreeNode* node=q.front();
       q.pop();
       csum+=node->val;
       if(node->left) q.push(node->left);
       if(node->right) q.push(node->right);
       }
       if(csum>maxsum)
       {
        maxsum=csum;
        ans=level;
       }
       level++;
       }
       return ans;
    }