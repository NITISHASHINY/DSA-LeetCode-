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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; //stores right view
        if(root == NULL){ //base case
            return ans;
        }
        queue<TreeNode*> q; //helps perform bfs
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop(); // removal of front node
                if(i == size-1)
                ans.push_back(node->val);
                if(node->left)
                q.push(node->left); //next levels
                if(node->right)
                q.push(node->right);

            }
        }
        return ans;


        
    }
};