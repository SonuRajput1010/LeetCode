class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int prefSum =0;
        int cnt = 0;
        HashMap<Integer,Integer> map = new HashMap<>();

        map.put(0,1);

        for(int i=0; i<n; i++){
            prefSum += nums[i];
            int remove = prefSum -k;
            cnt+= map.getOrDefault(remove,0);
            map.put(prefSum,map.getOrDefault(prefSum,0)+1);
        }
        
        return cnt;
    }
}