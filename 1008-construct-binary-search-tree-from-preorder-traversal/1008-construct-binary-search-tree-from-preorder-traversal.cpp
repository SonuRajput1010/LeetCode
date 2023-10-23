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
    TreeNode* buildTree(vector<int>& preorder,int mini, int maxi, int &i){
        if(i>= preorder.size()){
            return NULL;
        }
        if(preorder[i] < mini || preorder[i] > maxi){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = buildTree(preorder,mini,root->val,i);
        root->right = buildTree(preorder,root->val,maxi,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i=0;
        return buildTree(preorder,mini,maxi,i);
    }
};