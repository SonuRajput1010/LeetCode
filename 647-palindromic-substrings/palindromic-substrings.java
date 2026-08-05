class Solution {
    public boolean isPalindrome(String s,int l, int r){
        while(l<r){
            if(s.charAt(l) != s.charAt(r)) return false;

            l++;
            r--;
        }
        return true;
    }
    public int countSubstrings(String s) {

        int n = s.length();
        int cnt =0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s,i,j)) cnt++;
            }
        }
        return cnt;
        
    }
}