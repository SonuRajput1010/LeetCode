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
private: 
    pair<bool,int>isBalancefFast(TreeNode* root){
        
        if(root == NULL){
            pair<bool,int> pt(true,0);
            return pt;
        }
        pair<int,int> left = isBalancefFast(root->left);
        pair<int,int> right = isBalancefFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool,int> ans;
        
        ans.second = max(left.second , right.second) + 1 ;
        
        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancefFast(root).first;
    }
};