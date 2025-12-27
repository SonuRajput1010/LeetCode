class Solution {
    public int longestConsecutive(int[] nums) {


        if(nums.length == 0) return 0;

        HashSet<Integer> set = new HashSet<>();

        for(int x : nums){
            set.add(x);
        }

        int longest = 0;

        for(int x : set){

            if(!set.contains(x-1)){

                int current = x;
                int streak = 1;

                while(set.contains(current + 1)){
                    current++;
                    streak++;
                }
                longest =Math.max(longest,streak);
            }
        }
        return longest;
    }
}