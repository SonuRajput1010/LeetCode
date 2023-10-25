class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count = 0;
        int n = s.size();
        for(int i=n-1; i>=0; i--){
            
            if(s[i] == ' ' &&  count >0){
                return count;
            }
            if( s[i] != ' '){
                count++;
            }
        }
        return count;
    }
    
};