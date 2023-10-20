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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        stack<TreeNode*>st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* frontNode = st.top();
            st.pop();
            if(frontNode){
                st.push(frontNode->right);
                st.push(frontNode->left);
                
                swap(frontNode->left,frontNode->right);
                
            }
        }
        return root;
    }
};