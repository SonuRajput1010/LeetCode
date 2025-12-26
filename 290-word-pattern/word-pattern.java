class Solution {
    public boolean wordPattern(String pattern, String s) {

        String[] words = s.split(" ");
        Map<Character,String> map = new HashMap<>();
        Set<String> used = new HashSet<>();

        if(words.length != pattern.length() ) return false;

        for(int i=0; i<pattern.length(); i++){
            char c = pattern.charAt(i);
            String w = words[i];

            if(map.containsKey(c)){
                if(!map.get(c).equals(w)) return false;
            }
            else{
                if(used.contains(w)) return false;
                map.put(c,w);
                used.add(w);
            }
        }
        return true;
    }
}