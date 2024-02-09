#include <algorithm>

using namespace std;

class Node {
public:
    int val, min_val;
    Node* prev;
    Node(int val, Node* prev = NULL) {
        this->val = val;
        this->prev = prev;
        if (prev) {
            this->min_val = min(prev->min_val, this->val); 
        } else {
            this->min_val = this->val;
        }
    }
};

class MinStack {
public:
    Node* node = NULL;
    MinStack() {}
    
    void push(int val) {
        node = new Node(val, node);
    }
    
    void pop() {
        node = node->prev;
    }
    
    int top() {
        return node->val;
    }
    
    int getMin() {
        return node->min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */