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
 */
class Solution {
    
    int solve(TreeNode* root, bool isLeft){
        if(!root)
            return 0;
        if(isLeft && !root->left && !root->right)
            return root->val;
        
        int a=solve(root->left, true);
        int b=solve(root->right, false);
        return a+b;
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        return solve(root, false);
        
    }
};