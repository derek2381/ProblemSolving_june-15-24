// problem link
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/


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
    void treeTraversal(vector<vector<int>>& res,queue<TreeNode*>& currlvl, queue<TreeNode*>& nextlvl){
        if(currlvl.size() == 0){
            return ;
        }

        vector<int> arr;
        while(currlvl.size() != 0){
            TreeNode* node = currlvl.front();
            currlvl.pop();
            if(node){
                arr.push_back(node->val);

                if(node->left != nullptr){
                    nextlvl.push(node->left);
                }

                if(node->right != nullptr){
                    nextlvl.push(node->right);
                }
            }
        }

        res.push_back(arr);
        treeTraversal(res, nextlvl, currlvl);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res1, res2;
        if(!root){
            return res1;
        }
        queue<TreeNode*> q1, q2;
        q1.push(root);
        treeTraversal(res1, q1, q2);
        for(int i = 0; i < res1.size();i++){
            vector<int> arr;
            if(i%2 == 0){
                for(int j = 0;j < res1[i].size();j++){
                    arr.push_back(res1[i][j]);
                }
            }
            else{
                for(int j = res1[i].size()-1;j >= 0;j--){
                    arr.push_back(res1[i][j]);
                }
            }

            res2.push_back(arr);
        }

        return res2;



    }
};
