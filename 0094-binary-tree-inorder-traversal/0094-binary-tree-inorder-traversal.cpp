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
    
//     steps: 
    
//     1. Initialize current as root 
//     2. While current is not NULL
//        If current hs a left child
//           ifa) Make current as right child of the rightmost 
//              node in current's left subtree
//           ifb) Go to this left child, i.e., current = current->left
//        Else
//           ea) Print current’s data
//           eb) Go to the right, i.e., current = current->right
        
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        
        while(curr !=  NULL){
            
            if(curr->left){
                TreeNode* predecessor = curr->left;
                while(predecessor->right && predecessor->right != curr){
                    predecessor = predecessor->right;
                }
                if(predecessor -> right == NULL){
                    predecessor -> right = curr;
                    curr = curr->left;
                }
                else{
                    predecessor->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return ans;
    }
};
