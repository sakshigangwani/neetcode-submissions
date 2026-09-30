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
    int count = 0;
    void solve(TreeNode* root, int maxSoFar){
        if(root == NULL){
            return;
        }
        if(root -> val >= maxSoFar){
            maxSoFar = root -> val;
            count++;
        }
        solve(root -> left, maxSoFar);
        solve(root -> right, maxSoFar);
    }
    int goodNodes(TreeNode* root) {
        int maxSoFar = INT_MIN;
        solve(root, maxSoFar);
        return count;
    }
};
