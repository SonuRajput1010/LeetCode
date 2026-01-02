class Solution {
    public boolean isVowel(char x){
        return x=='a' || x=='e' || x=='i' || x=='o' ||
         x=='u'|| x=='A' ||  x=='E' ||  x=='I' || x=='O' || x=='U';
    }
    public String reverseVowels(String s) {
        int l = 0;
        int r = s.length()-1;

        char[] arr = s.toCharArray();


        while (l<r){
            if(!isVowel(arr[l])) l++;
            if(!isVowel(arr[r])) r--;

            if(isVowel(arr[l]) && isVowel(arr[r])){
                char ch = arr[l];
                arr[l] = arr[r];
                arr[r] = ch;

                l++;
                r--;
            }
        }
        return new String(arr);
        
    }
}