class Solution {
    public String convert(String s, int numRows) {
        int n = s.length()-1;
        
        if(numRows == 1){
            return s;
        }
        String ans = "";
        char[] s_array = s.toCharArray();
        int j;

        for(int i=0; i<numRows; i++){
            int increment = (numRows-1)*2;
            for(j=i; j<s.length(); j += increment){
                ans += s_array[j];
                if(i>0 && i<numRows-1 && (j+increment-2*i)<s.length()){
                    ans += s_array[j+increment -2*i];
                }
            }
        }
        return ans;

    }
}