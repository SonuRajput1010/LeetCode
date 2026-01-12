class Solution {
    public boolean isPowerOfThree(int n) {
        
        for(long i=1; i<=n; i *=3){
            if(i==n) return true;
        }
        return false;
    }
}