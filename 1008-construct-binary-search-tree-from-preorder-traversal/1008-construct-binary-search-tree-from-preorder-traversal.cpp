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

    TreeNode* dfs(vector<int>& preorder, int left, int right){

        if(left > right){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[left]);

        // Find first element greater than root
        int split = left + 1;
        while(split <= right && preorder[split] < root->val){
            split++;
        }

        // Build left subtree
        root->left = dfs(preorder, left + 1, split - 1);

        // Build right subtree
        root->right = dfs(preorder, split, right);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        return dfs(preorder, 0, preorder.size() - 1);

    }
};