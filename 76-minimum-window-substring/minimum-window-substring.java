class Solution {
    public String minWindow(String s, String t) {

// Best Approach

         Map<Character,Integer> tMap = new HashMap<>();
        for(char c : t.toCharArray()){
            tMap.put(c,tMap.getOrDefault(c,0)+1);
        }

        String ans = "";
        int l=0;
        int count = t.length();
        int minLen = Integer.MAX_VALUE;

        for(int r=0; r<s.length(); r++){
            char ch = s.charAt(r);

            if(tMap.containsKey(ch)){
                if(tMap.get(ch) > 0){
                    count--;
                }
                tMap.put(ch,tMap.get(ch)-1);
            }

            while(count == 0){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    ans = s.substring(l,r+1);
                }
                char leftCh = s.charAt(l);

                if(tMap.containsKey(leftCh)){
                    tMap.put(leftCh,tMap.get(leftCh)+1);
                    if(tMap.get(leftCh) > 0){
                    count++;
                    }
                }
                l++;
            }
        }



// Better Approach
        
        // Map<Character,Integer> tMap = new HashMap<>();
        // for(char c : t.toCharArray()){
        //     tMap.put(c,tMap.getOrDefault(c,0)+1);
        // }

        // String ans = "";
        // int l=0;
        // int count = t.length();
        // int minLen = Integer.MAX_VALUE;

        // Map<Character,Integer> sMap = new HashMap<>();

        // for(int r=0; r<s.length(); r++){
        //     char ch = s.charAt(r);
        //     sMap.put(ch,sMap.getOrDefault(ch,0)+1);

        //     if(tMap.containsKey(ch) && tMap.get(ch) >= sMap.get(ch)){
        //         count--;
        //     }

        //     while(count == 0){
        //         if(r-l+1 < minLen){
        //             minLen = r-l+1;
        //             ans = s.substring(l,r+1);
        //         }
        //         char leftChar = s.charAt(l);
        //         sMap.put(leftChar,sMap.getOrDefault(leftChar,0)-1);

        //         if(tMap.containsKey(leftChar) && tMap.get(leftChar) > sMap.get(leftChar)){
        //             count++;
        //         }
        //         l++;
        //     }
            // }   
        return ans;

        
    }
}