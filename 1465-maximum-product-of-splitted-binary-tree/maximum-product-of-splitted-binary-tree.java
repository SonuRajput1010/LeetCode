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

    long totalSum = 0;
    long maxProduct = 0;
    long MOD = 1000000007;
    
   
    public int maxProduct(TreeNode root) {

        totalSum = treeSum(root);

        dfs(root);

        return (int)(maxProduct % MOD);


    }
    public long treeSum(TreeNode root){
        if(root == null) return 0;
        
         return root.val + treeSum(root.left) + treeSum(root.right);
    }
    public long dfs(TreeNode root){
        if(root == null) return 0;

        long left = dfs(root.left);
        long right = dfs(root.right);

        long subSum = root.val + left + right;

        long product = subSum * (totalSum - subSum);
        maxProduct = Math.max(maxProduct,product);
        return subSum;
    }
}