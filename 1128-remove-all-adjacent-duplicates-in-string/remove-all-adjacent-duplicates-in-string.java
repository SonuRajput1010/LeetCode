class Solution {
    public String removeDuplicates(String s) {
        
         StringBuilder result = new StringBuilder();

        for(char ch : s.toCharArray()){
            int len = result.length();
            if(len > 0 && result.charAt(len-1) == ch){
               result.deleteCharAt(len-1);
            }
            else{
               result.append(ch);
            }
        }

        return result.toString();
    }
}