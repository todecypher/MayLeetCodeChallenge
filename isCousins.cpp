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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root , NULL});
        
        while(!q.empty()){
            bool first(0) , second(0);
            TreeNode *par1 , *par2;
            int n = q.size();
            while(n--){
                auto t = q.front();
                q.pop();
                if(t.first->val == x){
                    first = 1;
                    par1 = t.second;
                 }
                if(t.first->val == y){
                    second =1;
                    par2 = t.second;    
                }
                if(first and second){
                    if(par1==par2) return false;
                    return true;
                }
                if(t.first->left)
                    q.push({t.first->left,t.first});
                 if(t.first->right)
                    q.push({t.first->right,t.first});
            }
        }
        return false;
    }
};