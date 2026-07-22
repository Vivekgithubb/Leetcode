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
    int solve(TreeNode* node,int& count){
        if(!node)
            return 0;
        
        int cur = node->val;
        int lVal = solve(node->left,count);
        int rVal = solve(node->right,count);
        if( cur >= lVal && cur >= rVal)
            count++;
        
        cur = max({lVal , cur , rVal});
        return cur;
    }
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        int lasrgest = INT_MIN;
        solve(root,count);
        return count;
    }
};