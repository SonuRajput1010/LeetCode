class Solution {
    public int scoreOfParentheses(String s) {

        int count = 0;
        int score = 0;

        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '('){
                count++;
            }
            else{
                count--;
                if(s.charAt(i-1)=='(')  score += 1<<count;
            }
        }
        return score;

        // Stack<Integer> st = new Stack<>();
        // st.push(0);

        // for(char ch : s.toCharArray()){
        //     if(ch == '(') st.push(0);
        //     else{
        //         int val = st.pop();
        //         int score = Math.max(2*val,1);
        //         st.push(score+st.pop());
        //     }
        // }
        // return st.pop();

    }
}