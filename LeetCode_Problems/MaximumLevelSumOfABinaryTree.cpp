// problem link
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/



// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    void levelOrderTraversal(vector<int>& res, queue<TreeNode*>& currlvl, queue<TreeNode*>& nextlvl) {
        if (currlvl.empty()) {
            return;
        }
        int sum = 0;

        while (!currlvl.empty()) {
            TreeNode* node = currlvl.front();
            currlvl.pop();

            if (node) {
                sum += node->val;
                if (node->left != nullptr) {
                    nextlvl.push(node->left);
                }
                if (node->right != nullptr) {
                    nextlvl.push(node->right);
                }
            }
        }
        res.push_back(sum);
        levelOrderTraversal(res, nextlvl, currlvl);
    }

    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        vector<int> res;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        levelOrderTraversal(res, q1, q2);

        int maxSum = INT_MIN;
        int maxLevel = 0;

        for (int i = 0; i < res.size(); ++i) {
            if (res[i] > maxSum) {
                maxSum = res[i];
                maxLevel = i + 1;
            }
        }

        return maxLevel;
    }
};
