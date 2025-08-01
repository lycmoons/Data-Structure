// 1. 顺序存储
#define MaxSize 10
class Queue {
private:
    int data[MaxSize];
    int front = 0;     // 出队列时，需要出的元素的位置（空队列时与 rear 值相等）
    int rear = 0;      // 入队列时，元素需要进入的位置

public:
    bool empty() {
        return front == rear;
    }

    bool full() {
        return (rear + 1) % MaxSize == front;   // 还剩一个位置没用就认为已经满了
    }

    bool push(int num) {
        if(full()) return false;
        data[rear] = num;
        rear = (rear + 1) % MaxSize;
        return true;
    }

    bool pop() {
        if(empty()) return false;
        front = (front + 1) % MaxSize;
        return true;
    }
};


// 2. 链式存储
class Node {
public:
    int data;
    Node* next;

    Node(int dt) {
        data = dt;
        next = nullptr;
    }
};


class Queue {
private:
    Node* front = new Node(0);  // 头节点，不代表数据
    Node* rear = front;

public:
    bool empty() {
        return front == rear;
    }

    void push(int dt) {
        Node* node = new Node(dt);
        rear->next = node;
        rear = node;
    }

    bool pop() {
        if(empty()) return false;
        if(front->next == rear) {
            delete rear;
            front->next = nullptr;
            rear = front;
        }
        else {
            Node* temp = front->next;
            front->next = temp->next;
            delete temp;
        }
        return true;
    }

    ~Queue() {
        Node* temp;
        while(front != nullptr) {
            temp = front;
            front = front->next;
            delete temp;
        }
    }
};