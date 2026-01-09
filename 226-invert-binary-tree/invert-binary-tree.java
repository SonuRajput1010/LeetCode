/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root == null){
            return null;
        }

         Stack<TreeNode> st = new Stack<>();
        st.push(root);

        while (!st.isEmpty()) {
            TreeNode frontNode = st.pop();

            if (frontNode != null) {
                // swap left and right
                TreeNode temp = frontNode.left;
                frontNode.left = frontNode.right;
                frontNode.right = temp;

                // push children
                st.push(frontNode.left);
                st.push(frontNode.right);
            }
        }
        return root;
    }
}