class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;

        Arrays.sort(nums);

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            int s =i+1;
            int e = n-1;

            while(s < e){
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == 0){
                    ans.add(Arrays.asList(nums[i], nums[s], nums[e]));

                    while(s < e && nums[s] == nums[s+1]){
                        s++;
                    }
                    while(s < e && nums[e] == nums[e-1]){
                        e--;
                    }
                    s++;
                    e--;
                }
                else if( sum > 0){
                    e--;
                }
                else {
                    s++;
                }
            }
        }
        return ans;
    }
}