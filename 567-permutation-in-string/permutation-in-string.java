class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length()>s2.length()) return false;

        int[] freqS1 = new int[26];
        int[] freqS2 = new int[26];

        for(int i=0; i<s1.length(); i++){
            freqS1[s1.charAt(i)-'a']++;
        }

        int l = 0;

        for(int r=0; r<s2.length(); r++){

            freqS2[s2.charAt(r)-'a']++;

            if(r-l+1 > s1.length()){
                freqS2[s2.charAt(l)-'a']--;
                l++;
            }

            if(r-l+1 == s1.length()){
                boolean isMatch = true;
                for(int i=0; i<26; i++){
                    if(freqS1[i] != freqS2[i]){
                        isMatch = false;
                        break;
                    }
                }
            if(isMatch) return true;
            }
        }
        return false;
    }
}