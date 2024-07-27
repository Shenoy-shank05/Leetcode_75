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
    void check(TreeNode* root,int& count, int currmax){
        if(root==NULL){
            return ;
        }
        if(root->val>=currmax){
            count++;
            currmax=root->val;
        }
        check(root->left,count,currmax);
        check(root->right,count,currmax);
        
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        int currmax=root->val;
        check(root,ans,currmax);
        return ans;
    }
};