class Solution {
    public boolean detectCapitalUse(String word) {
        
        if(word.equals(word.toUpperCase())) return true;
        if(word.equals(word.toLowerCase())) return true;

        String first = word.substring(0,1);
        String last = word.substring(1);

        if(first.equals(first.toUpperCase()) && last.equals(last.toLowerCase())) return true;

        return false;
    }
}