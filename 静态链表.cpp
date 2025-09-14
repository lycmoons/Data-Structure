// 链表节点
class Node {
private:
    int data;    // 该节点的数据
    int next;    // 后续节点所在连续空间中的索引值
public:
    Node(int data, int next) {
        this->data = data;
        this->next = next;
    }

    Node() {
        this->data = 0;
        this->next = -1;
    }
};


int main() {
    // 静态链表，以第 0 个元素作为链表的头元素
    Node list[3];
    list[0] = Node(10, 2);
    list[1] = Node(22, -1);
    list[2] = Node(35, 1);
    return 0;
}

/**
 * 区别于指针数组
 * 静态列表是一个连续存储的对象数组
 * 但链表的顺序并不是数组的顺序
 * 而是按照对象内的 next 字段来拼接的
 * 
 * 数组中节点对象的顺序是其物理顺序
 * 通过对象内的 next 字段拼接的顺序是链表的顺序（逻辑顺序）
 */