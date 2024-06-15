// problem link
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    void traverseTree(vector<vector<int>>& res, queue<TreeNode*>& itr, queue<TreeNode*>& store){
        if(itr.size() == 0 && store.size() == 0){
            return ;
        }
        vector<int> arr;

        while(itr.size() != 0){
            TreeNode* node = itr.front();
            itr.pop();

            if(node){
                arr.push_back(node->val);
                if(node->left != nullptr){
                    store.push(node->left);
                }

                if(node->right != nullptr){
                    store.push(node->right);
                }
            }
        }

        if(arr.size() > 0){
            res.push_back(arr);
        }
        traverseTree(res, store, itr);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(!root){
            return res;
        }
        queue<TreeNode*> q1, q2;
        q1.push(root);
        traverseTree(res, q1, q2);
        return res;
    }
};
