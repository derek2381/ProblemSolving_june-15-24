// problem link
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/


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
    int depth(TreeNode* root, int count){
        if(!root)
        return count;

        int left = depth(root->left, count+1);
        int right = depth(root->right, count+1);

        return max(left, right);


    }
    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }
};
