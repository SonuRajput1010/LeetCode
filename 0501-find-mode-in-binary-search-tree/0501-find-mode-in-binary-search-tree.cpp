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
    int val = INT_MIN, freq = 0, maxFreq = 0;
    vector<int> ans;
    
    void inOrder(TreeNode* root){
        if(root== NULL){
            return;
        }
        inOrder(root->left);
        if(val == root->val){
            freq++;
        }
        else{
            val = root->val;
            freq = 1;
        }
        if (freq>maxFreq) {
            maxFreq=freq;
            ans={root->val};
        } 
        else if (freq==maxFreq) 
            ans.push_back(root->val);
        
        inOrder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};