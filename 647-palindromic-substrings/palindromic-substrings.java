class Solution {
    public int expand(String s, int l, int r){
        int n = s.length();
        int count = 0;
        while(l>=0 && r<n && s.charAt(l) == s.charAt(r)){
            count++;
            l--;
            r++;
        }
        return count;
    }
    public int countSubstrings(String s) {
        
        int cnt =0;
        for(int i=0; i<s.length(); i++){
            cnt += expand(s,i,i);
            cnt += expand(s,i,i+1);
        }
        return cnt;
    }
}