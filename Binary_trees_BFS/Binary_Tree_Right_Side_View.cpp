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
           vector<int> ans;
    if (root == NULL) return ans; 

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    TreeNode* prev = NULL;

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr == NULL) {
            if (prev != NULL) {
                ans.push_back(prev->val); 
            }
            if (!q.empty()) {
                q.push(NULL); 
            }
        } else {
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
        prev = curr; 
    }
    return ans;
    }
};