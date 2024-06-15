// problem link
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/


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
    void treeTraversal(stack<vector<int>>& stk, queue<TreeNode*>& currlvl, queue<TreeNode*>& nextlvl){
        if(currlvl.size() == 0 && nextlvl.size() == 0){
            return ;
        }
        vector<int> currlvlvalues;

        while(currlvl.size() != 0){
            TreeNode* node = currlvl.front();
            currlvl.pop();

            if(node){
                currlvlvalues.push_back(node->val);
                if(node->left != nullptr){
                    nextlvl.push(node->left);
                }

                if(node->right != nullptr){
                    nextlvl.push(node->right);
                }
            }
        }

        if(currlvlvalues.size() > 0){
                stk.push(currlvlvalues);
        }
        treeTraversal(stk, nextlvl, currlvl);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> stk;
        vector<vector<int>> res;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        treeTraversal(stk,q1, q2);
        cout << stk.size() << endl;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};
