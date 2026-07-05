class Solution {
    public long maximumSubarraySum(int[] nums, int k) {

        Set<Integer> set = new HashSet<>();
        int n = nums.length;
        int i = 0;
        long sum = 0;
        long maxSum = 0;

        for(int j=0; j<n; j++){

            while(set.contains(nums[j])){
                set.remove(nums[i]);
                sum -= nums[i];
                i++;
            }

            set.add(nums[j]);
            sum += nums[j];

            if(j-i+1 == k){
                maxSum = Math.max(sum,maxSum);
                set.remove(nums[i]);
                sum -= nums[i];
                i++;
            }
        }
        return maxSum;
    }
}