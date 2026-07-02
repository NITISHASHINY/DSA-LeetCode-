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
    int heightt;

    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left_height = height(root->left);
        if(left_height == -1) return -1;

        int right_height = height(root->right);
        if(right_height == -1) return -1;

        if(abs(left_height - right_height) > 1){
            return -1;
        }

        return 1 + max(left_height, right_height);
    }

    bool isBalanced(TreeNode* root) {
        heightt = height(root);

        if(heightt == -1){
            return false;
        }

        return true;
    }
};