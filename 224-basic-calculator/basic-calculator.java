class Solution {
    public int calculate(String s) {
        int n = s.length();
        Stack<Integer> st = new Stack<>();

        int num = 0;
        int op=1;
        int result = 0;

        for(int i=0; i<n; i++){

            int ch = s.charAt(i);

            if(Character.isDigit(ch)) num = num* 10 + (ch-'0');

            else if(ch == '+'){
                result += num * op;
                num = 0;
                op = 1;
                }

            else if(ch == '-'){
                result += num * op;
                num = 0;
                op = -1;
            }
            else if(ch == '('){
                st.push(result);
                st.push(op);
                result = 0;
                op = 1;
            }
            else if(ch == ')'){
                result += num * op;
                num = 0;

                result *= st.pop();
                result += st.pop();
            }
        }
        result += num * op;
        return result;
    }
}