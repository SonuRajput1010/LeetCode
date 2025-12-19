class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {

        int totalGas = 0;
        int totalCost = 0;

        for(int val : gas){
            totalGas += val;
        }

        for(int val : cost){
            totalCost += val;
        }

        if(totalGas < totalCost){
            return -1;
        }

        int start = 0;
        int currGas = 0;

        for(int i=0; i<cost.length; i++){
            currGas += (gas[i]-cost[i]);
            if(currGas < 0){
                start = i+1;
                currGas = 0;
            }
        }
        return start;
        
    }
}