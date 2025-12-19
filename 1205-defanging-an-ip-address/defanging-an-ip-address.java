class Solution {
    public String defangIPaddr(String address) {

        int n = address.length();
        StringBuilder ans = new StringBuilder();
        for(int i=0; i<n; i++){
            if(address.charAt(i) == '.'){
                ans.append("[.]");
            }
            else{
                ans.append(address.charAt(i));
            }
        }
        return ans.toString();
    }
}