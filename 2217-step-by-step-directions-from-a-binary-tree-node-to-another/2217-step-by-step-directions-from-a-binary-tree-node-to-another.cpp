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

    TreeNode* lca(TreeNode* root, int start, int end){
        if(!root)
            return NULL;
        if(root->val == start || root->val == end)
            return root;
        
        TreeNode* left = lca(root->left, start, end);
        TreeNode* right = lca(root->right, start, end);
        if(left && right)
            return root;
        return (left!=NULL)?left:right;
    }

    bool findPath(TreeNode* root, int value, string &path){
        if(!root)
            return false;
        if(root->val == value)
            return true;
        path.push_back('L');
        if(findPath(root->left, value, path))
            return true;
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right, value, path))
            return true;
        path.pop_back();
        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* LCA = lca(root, startValue, destValue);
        
        string pathForStart, pathForDest;
        findPath(LCA, startValue, pathForStart);
        findPath(LCA, destValue, pathForDest);

        string ans(pathForStart.size(), 'U');
        ans += pathForDest;
        return ans;

    }
};