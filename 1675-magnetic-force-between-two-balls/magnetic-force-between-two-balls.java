class Solution {
    public boolean canWePlace(int[] position, int m, int force){
        int cntBall=1;
        int lastBall = position[0];

        for(int i=1; i<position.length; i++){
            if(position[i]-lastBall >= force){
                cntBall ++;
                lastBall = position[i];
            }
            if(cntBall >= m) return true;
        }
        return false;
    }
    public int maxDistance(int[] position, int m) {
        
        Arrays.sort(position);

        int n = position.length;

        int low = 1;
        int high = position[n-1]-position[0];

        while(low <= high){

            int force = low + (high-low)/2;

            if(canWePlace(position,m,force)) low = force + 1;

            else high = force - 1;
        }

        return high;
    }
}