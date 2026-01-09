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
    public boolean recur(TreeNode root,int sum,int target){
        if(root == null)
        {
            return false;
        }
        sum += root.val;
        if (sum == target && root.left == null && root.right == null) {
        return true;
        }
        return recur(root.left,sum,target) || recur(root.right,sum,target);
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return recur(root,0,targetSum);
    }
}