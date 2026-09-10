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
public:
    int count = 0;
    int solve(TreeNode* root, int& rootCount){
        if(!root){
            rootCount = 0;
            return 0;
        }
        int lCount = 0;
        int rCount = 0;
        
        int lsum = solve(root->left,lCount);
        int rsum = solve(root->right,rCount);

        rootCount = lCount + rCount + 1;
        int sum = (lsum + rsum + root->val);
        int avg = sum / rootCount;
        
        if(avg == root->val) 
            count++;

        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        int rootCount = 0;
        solve(root,rootCount);
        return count;
    }
};