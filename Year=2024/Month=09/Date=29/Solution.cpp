// Problem Link : https://leetcode.com/problems/design-circular-deque/description/


// Solution //
class Node{
public:
    int data;
    Node *prev, *next;
    Node(int data){
        this->data = data;
        this->prev = this->next = NULL;
    }
};

class MyCircularDeque {
private:
    Node *front, *rear; 
    int currSize, maxSize;
public:
    MyCircularDeque(int k) {
        front = rear = NULL;
        currSize = 0;
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if( currSize < maxSize ){
            Node *newNode = new Node(value);
            if( front == NULL ){
                front = rear = newNode;
            } else{
                front->prev = newNode;
                newNode->next = front;
                front = newNode;
            }
            currSize += 1;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if( currSize < maxSize ){
            Node *newNode = new Node(value);
            if( rear == NULL ){
                front = rear = newNode;
            } else{
                rear->next = newNode;
                newNode->prev = rear;
                rear = newNode;
            }
            currSize += 1;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if( currSize > 0 ){
            if( front == rear ){
                front = rear = NULL;
            } else{
                Node *next = front->next;
                front->next = NULL;
                next->prev = NULL;
                front = next;
            }
            currSize -= 1;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if( currSize > 0 ){
            if( front == rear ){
                front = rear = NULL;
            } else{
                Node *prev = rear->prev;
                rear->prev = NULL;
                prev->next = NULL;
                rear = prev;
            }
            currSize -= 1;
            return true;
        }
        return false;
    }
    
    int getFront() {
        return (currSize > 0? front->data : -1);
    }
    
    int getRear() {
        return (currSize > 0? rear->data : -1);
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == maxSize;
    }
};