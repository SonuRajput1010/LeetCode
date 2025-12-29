class Solution {
    public int lengthOfLongestSubstring(String s) {

        int[] lastIndex = new int[128];
        int left = 0;
        int n = s.length();
        int maxLen = 0;

        for(int right = 0; right<n; right++){
            char c = s.charAt(right);

            left = Math.max(left,lastIndex[c]);
            maxLen = Math.max(maxLen, right-left+1);

            lastIndex[c] = right+1;

        }

        return maxLen;

        
    }
}