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

    void answer(TreeNode* root,int val,TreeNode*& ans){
        if(root==NULL){
            ans=NULL;
            return ;
        }
        if(root->val==val){
                ans=root;
                return ;
              }
       
        if(root->val>val){
              answer(root->left,val,ans);
              


        }
        if(root->val<val){
            answer(root->right,val,ans);
         
        }

    }
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* ans=NULL;
        answer(root,val,ans);
        return ans;
    }
};