class CustomStack {

    int[] inc;
    int [] st;
    int index ;
    int maxSize ;

    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        st = new int[maxSize];
        inc = new int[maxSize];
        index = -1;
    }
    
    public void push(int x) {
        if(index == maxSize-1){
            return ;
        }
        index++;
        st[index] = x;
    }
    
    public int pop() {
        if(index == -1) return -1;
        // int val = st[index];
        // index--;

        int result = inc[index] + st[index];
        if(index > 0){
            inc[index-1] += inc[index];
        }
        inc[index] = 0;
        index--;

        return result;

        // return val;
    }
    
    public void increment(int k, int val) {
        // int limit = Math.min(k,index+1);
        // for(int i=0; i<limit; i++){
        //     st[i] += val;
        // }

        int idx = Math.min(index,k-1);
        if(idx >= 0){
            inc[idx] += val;
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */