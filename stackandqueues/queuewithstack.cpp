class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    int front;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
            front=x;
            return;
        }
        s1.push(x);
    }
    
    int pop() {
        int x=-1;
        if(s2.empty()){
            if(s1.empty())return x;
            else {
                while(!s1.empty()){
                    int temp = s1.top();
                    s1.pop();
                    s2.push(temp);
                }
            }
        }
        
        x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
       if(s1.empty() && s2.empty())return -1;
        if(!s2.empty())return s2.top();
        else return front;
    }
    
    bool empty() {
        return (s1.empty() && s2.empty()) ;
    }
};