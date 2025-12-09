class Solution {
    public String longestCommonPrefix(String[] strs) {
         if (strs == null || strs.length == 0) return "";

        String first = strs[0];

        for (int i = 0; i < first.length(); i++) {
            char c = first.charAt(i);

            for (int j = 1; j < strs.length; j++) {
                // If index goes out OR character mismatch
                if (i >= strs[j].length() || strs[j].charAt(i) != c) {
                    return first.substring(0, i);
                }
            }
        }
        return first; 
    }
}