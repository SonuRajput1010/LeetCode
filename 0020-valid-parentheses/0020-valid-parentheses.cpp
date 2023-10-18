class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int idx = 0;

        if(s.size() == 0){
            return true;
        }

        while(idx < s.size()){

            if( s[idx] == '(' || s[idx] == '[' || s[idx] == '{' ){
                stack.push(s[idx]);
            }
            else if ( (s[idx] == ')' && !stack.empty() && stack.top() == '(') ||
                        (s[idx] == '}' && !stack.empty() && stack.top() == '{') ||
                        (s[idx] == ']' && !stack.empty() && stack.top() == '[')
                      ){
                stack.pop();
            }
            else {
                return false;   
            }
            idx++; 
        }
        if(stack.empty()) {
            return true;
        }
        return false;
    }
};
