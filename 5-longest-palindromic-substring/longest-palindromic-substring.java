class Solution {
    public int expand(String s, int l, int r){
        int n=s.length();
        while(l>=0 && r<n && s.charAt(l) == s.charAt(r)){
            l--;
            r++;
        }
        return r-l-1;
    }
    public String longestPalindrome(String s) {

        int n = s.length();
        String result="";
        int start=0,end=0;

        for(int i=0; i<n; i++){
            int oddLen = expand(s,i,i);
            int evenLen = expand(s,i,i+1);

            int len = Math.max(oddLen,evenLen);

            if(len > end - start ){
                start = i- ( len-1)/2;
                end = i + (len/2);
            }
        }
         result = s.substring(start,end+1);
        return result;
    }
}