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
    int count = 0;
    pair<int,int> countSum(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        auto left = countSum(root->left);
        auto right = countSum(root->right);
        int sum = ( root->val + left.first + right.first );
        int n = left.second + right.second + 1;
        count += ((sum/n) == root->val);
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        auto p1 = countSum(root);
        return count;
    }
};