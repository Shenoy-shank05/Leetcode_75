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

    void traverse(TreeNode* root, stack<int>&s){

        if(root==NULL){
            return;
        }
        traverse(root->left,s);
        if(!root->right && !root->left){
            s.push(root->val);
        }
        traverse(root->right,s);
    }
  bool check(TreeNode* root, stack<int>& s) {
    if (root == NULL) {
        return true;
    }
    if (!check(root->right, s)) {
        return false;
    }
    if (!root->left && !root->right) {
        if (s.empty() || root->val != s.top()) {
            return false;
        }
        s.pop();
    }
    return check(root->left, s);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    stack<int> s;
    traverse(root1, s); 
    return check(root2, s) && s.empty();
}
};