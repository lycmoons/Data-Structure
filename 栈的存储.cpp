// 1. 顺序存储方式（用数组存储）
#define MaxSize 10
class Stack {
private:
    int data[MaxSize];
    int top = -1;      // 指向栈顶元素

public:
    // 判空
    bool empty() {
        return this->top == -1;
    }

    // 入栈
    bool push(int num) {
        if(this->top == MaxSize - 1) {
            return false;
        }
        else {
            this->top++;
            this->data[this->top] = num;
            return true;
        }
    }
    
    // 出栈
    bool pop() {
        if(this->top == -1) {
            return false;
        }
        else {
            this->top--;
            return true;
        }
    }
};