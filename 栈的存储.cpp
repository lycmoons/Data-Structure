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

// 2. 链式存储方式（使用单链表来存储）
// 头节点的 next 指针指向的元素是栈顶元素
class Node {
public:
    int data;
    Node* next;

    Node(int dt) {
        data = dt;
        next = nullptr;
    }
};

class Stack {
private:
    Node* head = new Node(0);  // 头节点不代表数据

public:
    // 判空
    bool empty() {
        return head->next == nullptr;
    }

    // 入栈
    void push(int num) {
        Node* node = new Node(num);
        node->next = head->next;
        head->next = node;
    }

    // 出栈
    bool pop() {
        if(empty()) return false;
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
    }

    // 释放空间
    ~Stack() {
        Node* temp;
        while(head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};