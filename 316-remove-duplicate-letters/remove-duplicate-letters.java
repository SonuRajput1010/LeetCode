class Solution {
    public String removeDuplicateLetters(String s) {
        
        int[] lastIndex = new int[26];
        boolean[] visited = new boolean[26];

        for(int i=0; i<s.length(); i++){
            lastIndex[s.charAt(i)-'a'] = i;
        }

        StringBuilder sb = new StringBuilder();

        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);

            if(visited[ch-'a']) continue;

            while((!sb.isEmpty())  && (sb.charAt(sb.length()-1) > ch ) && lastIndex[sb.charAt(sb.length()-1) - 'a' ] > i){

               visited[sb.charAt(sb.length()-1) - 'a'] = false;
                sb.deleteCharAt(sb.length()-1);
            }

            sb.append(ch);
            visited[ch-'a'] = true;
        }

        return sb.toString();
    }
}