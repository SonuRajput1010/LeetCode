class Solution {
    public int lengthOfLongestSubstring(String s) {

        int maxLen = 0;
        int l = 0;

        // for(int r=0; r<s.length(); r++){
        //     Set<Character> set = new HashSet<>();
        //     char ch = s.charAt(r);
        //     if(set.contains(ch)){
        //         max = Math.max(max,r-l+1);
        //         l++;
        //     }
        //     else{
        //         set.add(ch);
        //     }
        // }

        for(int i=0; i<s.length(); i++){
            Set<Character> set = new HashSet<>();
            for(int j=i; j<s.length(); j++){
                char ch = s.charAt(j);
                if(set.contains(ch)) break;
                set.add(ch);

                maxLen = Math.max(maxLen, j-i+1);

            }
        }


        return maxLen;
    }
}