class Solution {
    public int getSum(int n){
        int sum =0;
        while(n > 0){
            int d = n%10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    public boolean isHappy(int n) {

       HashSet<Integer> seen = new HashSet<>();
       while(n != 1){
        if(seen.contains(n)) return false; // cycle detected

            seen.add(n);
            n = getSum(n);
       }
       return true;

        
    }
}