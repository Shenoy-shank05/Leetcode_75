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
     int maxlength=INT_MIN;
     void doit(TreeNode* root,int dir,int length){

        if(root==NULL){
            return ;
        }
        maxlength=max(maxlength,length);
        doit(root->left,0,dir?length+1:1);
        doit(root->right,1,dir?1:length+1);

        
        
     }
    int longestZigZag(TreeNode* root) {
        
        doit(root,0,0);
        doit(root,1,0);
        return maxlength;
    }
};