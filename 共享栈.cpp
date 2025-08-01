// 一片连续的内存空间来存储两个栈的内容
// 一个自下而上，一个自上而下

#define MaxSize 10

class SharedStack {
private:
    int data[MaxSize];
    int bottom = -1;
    int top = MaxSize;

    // 判断共享空间是否已经用完
    bool full() {
        return top == bottom + 1;
    }

    // 第一个栈判空
    bool empty1() {
        return bottom == -1;
    }

    // 第二个栈判空
    bool empty2() {
        return top == MaxSize;
    }

    // 第一个栈入栈
    bool push1(int num) {
        if(full()) return false;
        bottom++;
        data[bottom] = num;
    }

    // 第二个栈入栈
    bool push2(int num) {
        if(full()) return false;
        top--;
        data[top] = num;
    }

    // 第一个栈出栈
    bool pop1() {
        if(empty1()) return false;
        bottom--;
    }

    // 第二个栈出栈
    bool pop2() {
        if(empty2()) return false;
        top++;
    }
};