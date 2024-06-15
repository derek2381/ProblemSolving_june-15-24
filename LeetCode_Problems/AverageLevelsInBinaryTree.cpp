// problem link
// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/


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
void treeTraversal(vector<double>& res, queue<TreeNode*>& currlvl, queue<TreeNode*>& nextlvl){
        if(currlvl.size() == 0){
            return ;
        }

        double sum = 0;
        int n = 0;
        while(currlvl.size() != 0){
            TreeNode* node = currlvl.front();
            currlvl.pop();

            if(node){
                sum += node->val;
                if(node->left != nullptr){
                    nextlvl.push(node->left);
                }

                if(node->right != nullptr){
                    nextlvl.push(node->right);
                }
            }
            n++;
        }

        sum = sum / n;


        res.push_back(sum);
        treeTraversal(res, nextlvl, currlvl);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q1, q2;

        q1.push(root);

        treeTraversal(res, q1, q2);
        return res;
    }
};
