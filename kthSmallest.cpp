/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans ;
   void pre(TreeNode* root , int k,int &ct ){
       if(!root) return ;
       pre(root->left,k,ct);
              ct+=1;
              if(ct ==k){
                  ans = root->val;
                  return ;
              }
         pre(root->right,k,ct);
   }
    int kthSmallest(TreeNode* root, int k ) {
        int v= 0;
        pre(root , k ,v);
        return ans;
    }
    
};