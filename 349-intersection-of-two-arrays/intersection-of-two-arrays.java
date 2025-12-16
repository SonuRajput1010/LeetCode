class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> ans = new HashSet<>();
        HashSet<Integer> result = new HashSet<>();

        for(int num : nums1){
            ans.add(num);
        }
        for(int num : nums2){
            if(ans.contains(num)){
                result.add(num);
            }
        }
        int[] answer = new int[result.size()];
        int i=0;
        for(int num : result){
            answer[i++] = num
            ;
        }

        return answer;

    }

}