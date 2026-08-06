class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();

        if(p.length() > s.length() ) return res;

        Map<Character,Integer> pMap = new HashMap<>();
        Map<Character,Integer> sMap = new HashMap<>();

        for(char c : p.toCharArray()){
            pMap.put(c, pMap.getOrDefault(c,0)+1);
        }

        int l =0; 
        int count = p.length();

        for(int r=0; r<s.length(); r++){
            char ch = s.charAt(r);

            sMap.put(ch,sMap.getOrDefault(ch,0)+1);

            if(pMap.containsKey(ch) && sMap.get(ch) <= pMap.get(ch)){
                count--;
            }

            if(r-l+1 > p.length()){
                char leftCh = s.charAt(l);
                if(pMap.containsKey(leftCh) && sMap.get(leftCh) <= pMap.get(leftCh)){
                    count++;
                }
                    sMap.put(leftCh,sMap.get(leftCh)-1);
                    l++;
            }
            if(count == 0) res.add(l);

        }

        return res;

// Brute Force Approach

        //  List<Integer> res = new ArrayList<>();
        // int n = s.length();
        // int k = p.length();

        // int[] pCount = new int[26];

        // for(char c : p.toCharArray()){
        //     pCount[c-'a']++;
        // }

        // for(int i=0; i<= n-k; i++){
        //     int[] sCount = new int[26];
        //     for(int j=i; j<i+k; j++){
        //         sCount[s.charAt(j)-'a']++;
        //     }

        //     if(Arrays.equals(sCount,pCount)) res.add(i);
        // }
        // return res;
    }
}