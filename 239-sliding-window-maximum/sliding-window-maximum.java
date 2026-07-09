class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        int n= nums.length;
        int[] ans = new int[n-k+1];
        Deque<Integer> dq = new LinkedList<>();

        for(int r=0; r<n; r++){

            while(!dq.isEmpty() && dq.peekFirst() <= r-k){
                dq.pollFirst();
            }
            while(!dq.isEmpty() && nums[dq.peekLast()] < nums[r]){
                dq.pollLast();
            }

            dq.add(r);

            if(r >= k-1){
                ans[r-k+1] = nums[dq.peekFirst()];
            }
        }
        return ans;

        
    }
}