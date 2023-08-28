// Problem Link : https://leetcode.com/problems/implement-stack-using-queues/


// Solution //
class MyStack {
public:
    queue<int> q;
    int topEle;
    MyStack() {
        // q.clear();
        topEle = -1;
    }
    
    void push(int x) {
        q.push(x);
        topEle = x;
    }
    
    int pop() {
        int size = q.size();
        int lastEle = -1;
        while( size > 0 ){
            auto ele = q.front();
            lastEle = ele;
            q.pop();
            size -= 1;
            if( size ){
                q.push(ele);
                topEle = ele;
            }
        }
        return lastEle;
    }
    
    int top() {
        return topEle;
    }
    
    bool empty() {
        return q.empty();
    }
};