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
    void solve(string str, string &ans,TreeNode* &root){
        if(!root)return;
        str = (char)(root->val+'a') + str;
        solve(str,ans,root->left);
        solve(str,ans,root->right);
        if((ans == "" || str<ans) && root->left == NULL && root->right == NULL){
            ans = str;
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string str = "";
        solve(str,ans,root);
        
        return ans;  
    }
};