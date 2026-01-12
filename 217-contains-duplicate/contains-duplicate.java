class Solution {
    public boolean containsDuplicate(int[] nums) {
        int n = nums.length;

        HashSet<Integer> ans  = new HashSet<>();

        // for(int i=0; i<n; i++){
        //     if(ans.contains(nums[i])) return true;
        //     else return false;
        // }

        // return true;

        for(int i=0; i<n; i++){
            ans.add(nums[i]);
        }

        if(ans.size() != n) return true;

        return false;
    }
}