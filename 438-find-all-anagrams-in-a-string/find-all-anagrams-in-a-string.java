class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();

        int n = s.length();
        int k = p.length();

        int[] pCount = new int[26];

        for(char c : p.toCharArray()){
            pCount[c-'a']++;
        }

        for(int i=0; i<= n-k; i++){
            int[] sCount = new int[26];
            for(int j=i; j<i+k; j++){
                sCount[s.charAt(j)-'a']++;
            }

            if(Arrays.equals(sCount,pCount)) res.add(i);
        }
        return res;
    }
}