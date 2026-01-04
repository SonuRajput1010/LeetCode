class Solution {
    public int findSumDivisor(int x){
        int count=0;
        int sum =0;
        for(int i=1; i<=Math.sqrt(x); i++){
            
            if( x % i == 0){
                int other = x/i;
                if(other == i){
                    count++;
                    sum += i;
                }
                else{
                    count +=2;
                    sum += i + other;
                } 
            }
            if(count > 4) return 0;
        }

        return count == 4 ? sum :0;
    }
    public int sumFourDivisors(int[] nums) {
        int result = 0;
        for(int x : nums){
            result += findSumDivisor(x);
        }
        return result;
    }
}