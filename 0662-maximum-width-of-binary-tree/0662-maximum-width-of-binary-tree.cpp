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
    int widthOfBinaryTree(TreeNode* root) {

        int width = 0;
        TreeNode* Node = root;

        if(root == NULL){
            return width;
        }

        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()){

            int size = q.size();

            long long firstIdx = q.front().second;
            long long lastIdx = q.back().second;

            width = max(width, (int)(lastIdx - firstIdx + 1));

            for(int i = 0; i < size; i++){

                TreeNode* node = q.front().first;
                long long currIdx = q.front().second - firstIdx;

                q.pop();

                if(node->left){
                    q.push({node->left, 2*currIdx + 1});
                }

                if(node->right){
                    q.push({node->right, 2*currIdx + 2});
                }
            }
        }

        return width;
    }
};