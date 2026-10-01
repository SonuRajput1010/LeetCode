class Solution {
    public String minRemoveToMakeValid(String s) {

        StringBuilder first = new StringBuilder();
        int open = 0;

        for(char ch : s.toCharArray()){
            if(ch == '('){
                open++;
                first.append(ch);
            }
            else if( ch == ')'){
                if(open > 0){
                    open--;
                    first.append(ch);
                }
            }
            else first.append(ch);
        }

        StringBuilder ans = new StringBuilder();
        int close = 0;

        for(int i=first.length()-1; i>=0; i--){
            char ch = first.charAt(i);
            if(ch == ')'){
                close++;
                ans.append(ch);
            }
            else if( ch == '('){
                if(close > 0){
                    close--;
                    ans.append(ch);
                }
            }
            else ans.append(ch);
        }

        return ans.reverse().toString();

        // Stack<Integer> st = new Stack<>();
        // char[] arr = s.toCharArray();

        // for(int i=0; i<s.length(); i++){
        //     if(s.charAt(i) == '('){
        //         st.push(i);
        //     }
        //     else if(s.charAt(i) == ')'){
        //         if(!st.isEmpty()) st.pop();
        //         else arr[i] = '#';
        //     }
        // }

        // while(!st.isEmpty()){
        //     arr[st.pop()] = '#';
        // }

        // StringBuilder sb = new StringBuilder();

        // for(char ch : arr){
        //     if( ch != '#'){
        //         sb.append(ch);
        //     }
        // }
        // return sb.toString();
    }
}