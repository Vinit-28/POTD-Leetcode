// Problem Link : https://leetcode.com/problems/implement-queue-using-stacks/description/


// Solution //
class MyQueue {
public:
    stack<int> s1, s2;
    int top;
    MyQueue() {
        s1 = stack<int>();
        s2 = stack<int>();
    }
    
    void push(int x) {
        if( s1.empty() ) top = x;
        s1.push(x);
    }
    
    int pop() {
        if( s2.empty() ){
            while( !s1.empty() ){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ele = s2.top(); s2.pop();
        return ele;
    }
    
    int peek() {
        if( s2.empty() ) return top;
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
