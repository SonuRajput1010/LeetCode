class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = Integer.MIN_VALUE;
        int minPrice = prices[0];
        
        for(int num : prices){
            if(minPrice > num){
                minPrice = num;
            }
            else 
                maxProfit = Math.max(maxProfit, num-minPrice);
        }
        return maxProfit;
    }
}