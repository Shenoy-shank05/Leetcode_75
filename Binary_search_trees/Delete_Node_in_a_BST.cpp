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


   void search(TreeNode* root,TreeNode* prev,int key){
    if(root==NULL){
        return ;
    }
    
    if(root->val<key){
        
        search(root->right,root,key);
    }
    if(root->val==key){
        deleting(root,prev);
    }
    else if(root->val>key){
        search(root->left,root,key);
    }


   }

   void deleting(TreeNode* root ,TreeNode* prev){
    if(!root->right && !root->left){
       if (prev->left == root) {
            prev->left = NULL;
        }
        else {
             prev->right = NULL;
        }
      
    }
    else if(root->left && !root->right){
        if(prev->left==root){
            prev->left=root->left;
            
        }
        else{
            prev->right=root->left;
            
        }
    }
    else if(root->right && !root->left){
        if(prev->left==root){
            prev->left=root->right;
            
        }
        else{
            prev->right=root->right;
        }
        
        return ;
    }
    else if(root->right && root->left){

        TreeNode* temp=root->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        temp->left=root->left;
        if(prev->left==root){
            prev->left=root->right;
        }
        else{
            prev->right=root->right;
        }
       
    }
   }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            if(!root->left && !root->right){
                return NULL;
            }
            else if(!root->left && root->right){
                return root->right;
            }
            else if(!root->right && root->left){
                return root->left;
            }
            else{
                TreeNode* temp=root->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                temp->left=root->left;
                return root->right;
            }
        }
        search(root,NULL,key);
        return root;
    }
};