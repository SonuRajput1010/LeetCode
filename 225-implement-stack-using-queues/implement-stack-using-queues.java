class MyStack {

    Queue<Integer>q1;
    Queue<Integer>q2;
    public MyStack() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
    }
    
    public void push(int x) {

        q1.offer(x);

    //     q2.offer(x);

    //     while(!q1.isEmpty()){
    //         q2.offer(q1.poll());
    //     }
    //    q1=q2;
    //    q2 = new LinkedList<>();
    }
    
    public int pop() {

        while(q1.size() > 1){
            q2.offer(q1.poll());
        }
        int val = q1.poll();
        q1= q2;
        q2 = new LinkedList<>();
        return val;

        // return q1.poll();
    }
    
    public int top() {
        while(q1.size() > 1){
            q2.offer(q1.poll());
        }
         int val = q1.poll();
        // Put the top element back
        q2.offer(val);
        q1= q2;
        q2 = new LinkedList<>();
        return val;


        // return q1.peek();
    }
    
    public boolean empty() {
        return q1.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */