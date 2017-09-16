#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> dataStack;
    stack<int> minStack;
    /** initialize your data structure here. */
    void push(int x) {
        dataStack.push(x);
        if (minStack.empty()) {
            minStack.push(x);
            return;
        }

        int minnum = minStack.top();
        if (minnum >= x) {
            minStack.push(x);
        }

    }

    void pop() {
        int num = dataStack.top();
        int minnum = minStack.top();
        if (num == minnum) {
            dataStack.pop();
            minStack.pop();
            return;
        }
        dataStack.pop();

    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack obj;
    obj.push(1);
    obj.push(3);
    obj.push(5);
    cout << obj.getMin();
    obj.pop();
    cout << obj.getMin();
}





