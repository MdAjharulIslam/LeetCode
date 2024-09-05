class MyStack {
public:
    
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
            int s=q.size();
        for(int i=0;i<s-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int element=q.front();
        q.pop();
        return element;
    }
    
    int top() {
       return q.front(); 
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */