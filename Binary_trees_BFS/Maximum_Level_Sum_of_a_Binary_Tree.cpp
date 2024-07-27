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
    int maxLevelSum(TreeNode* root) {
        

        int count=1;
        int sum=0;
        int maxsum=INT_MIN;
        int maxlvl=1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                if(sum>maxsum){
                    maxsum=sum;
                    maxlvl=count;
                }
                count++;
                sum=0;
            }
            else{
                sum+=temp->val;

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

        }
        return maxlvl;
    }
};