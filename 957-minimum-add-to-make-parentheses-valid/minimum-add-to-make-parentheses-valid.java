class Solution {
    public int minAddToMakeValid(String s) {
        
        Stack<Character> st = new Stack<>();
        int closing = 0;

        for(char ch : s.toCharArray()){
            if(ch == '('){
                st.push(ch);
            }
            else{
                if(!st.isEmpty()){
                    st.pop();
                }
                else{
                    closing++;
                }
            }
        }
        return st.size()+ closing;
    }
}