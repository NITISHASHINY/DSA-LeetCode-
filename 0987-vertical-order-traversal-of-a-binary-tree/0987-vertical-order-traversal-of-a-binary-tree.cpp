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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        // column -> row -> multiset of node values
        map<int, map<int, multiset<int>>> mp;

        // node, row, column
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()){

            TreeNode* Node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;

            q.pop();

            mp[col][row].insert(Node->val);

            if(Node->left){
                q.push({Node->left, {row + 1, col - 1}});
            }

            if(Node->right){
                q.push({Node->right, {row + 1, col + 1}});
            }
        }

        for(auto &col : mp){

            vector<int> nodess;

            for(auto &row : col.second){

                for(auto val : row.second){
                    nodess.push_back(val);
                }
            }

            ans.push_back(nodess);
        }

        return ans;
    }
};