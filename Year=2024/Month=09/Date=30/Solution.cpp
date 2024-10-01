// Problem Link : https://leetcode.com/problems/design-a-stack-with-increment-operation/description/


// Solution //
class CustomStack {
private:
    vector<int> arr;
    int maxSize;
public:
    CustomStack(int maxSize) {
        arr = vector<int>();
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if( arr.size() < maxSize ){
            arr.push_back(x);
        }
    }
    
    int pop() {
        int ele = -1;
        if( !arr.empty() ) ele = arr.back(), arr.pop_back();
        return ele;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min((int)arr.size(), k); i++){
            arr[i] += val;
        }
    }
};