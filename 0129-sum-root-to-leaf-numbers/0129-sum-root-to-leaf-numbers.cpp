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
    
    int solve(TreeNode* root, int sum){
        if(!root)
            return 0;
        
        sum = sum*10 + root->val;
        if(!root->left && !root->right)
            return sum;
        
        int a=solve(root->left, sum);
        int b=solve(root->right, sum);
        
        return (a+b);
        
    }
    
public:
    int sumNumbers(TreeNode* root) {
        
        return solve(root, 0);
        
    }
};