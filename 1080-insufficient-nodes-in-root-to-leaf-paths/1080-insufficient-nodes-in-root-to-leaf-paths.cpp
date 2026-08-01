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
    bool solve(TreeNode* node , int limit , int sum){
        if(!node->left && !node->right){
            return (sum + node->val) >= limit;
        }

        bool c1= false;
        bool c2= false;
        if(node->left)
            c1 = solve(node->left,limit,sum + node->val);
        if(node->right)
            c2 = solve(node->right,limit,sum + node->val);
        
        if(c1 == false) node->left = NULL;
        if(c2 == false) node->right = NULL;
        
        return c1 || c2;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool check = solve(root,limit,0);
        if(check == false) return {};
        return root;
    }
};