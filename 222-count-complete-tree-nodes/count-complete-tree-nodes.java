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
    private int leftDepth(TreeNode root){
        int h = 0;
        while(root != null) {
            h++;
            root = root.left;
        }
        return h;
    }
    private int rightDepth(TreeNode root){
        int h = 0;
        while(root != null) {
            h++;
            root = root.right;
        }
        return h;
    }
    public int countNodes(TreeNode root) {
        if(root == null) return 0;

        int leftRoot = leftDepth(root);
        int rightRoot = rightDepth(root);

        if(leftRoot == rightRoot){
            return (1<<leftRoot)-1;
        }

        return 1+countNodes(root.left)+countNodes(root.right); 


    }
}