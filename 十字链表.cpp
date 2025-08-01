// 十字链表用于存储稀疏矩阵
// 一个非零元素节点用五个字段来表示
class Node{
public:
    int row;          // 非零元所在的行索引
    int col;          // 非零元所在的列索引
    int data;         // 非零元的值
    Node* row_next;   // 指向同一行下一个非零元节点的指针
    Node* col_next;   // 指向同一列下一个非零元节点的指针

    Node(int row, int col, int data) {
        this->row = row;
        this->col = col;
        this->data = data;
        this->row_next = nullptr;
        this->col_next = nullptr;
    }
};

/**
 * 示例矩阵如下：
 * [[0, 0, 3, 8],
 *  [0, 2, 0, 0],
 *  [0, 0, 0, 0],
 *  [1, 0, 5, 0]]
 */

int main() {
    int row = 4;
    int col = 4;
    Node** row_start = new Node*[row];   // 指向对应行的首个非零元节点的指针
    Node** col_start = new Node*[col];   // 指向对应列的首个非零元节点的指针

    // 按行存储非零元
    row_start[0] = new Node(0, 2, 3);
    row_start[0]->row_next = new Node(0, 3, 8);
    row_start[1] = new Node(1, 1, 2);
    row_start[2] = nullptr;
    row_start[3] = new Node(3, 0, 1);
    row_start[3]->row_next = new Node(3, 2, 5);

    // 按列存储非零元（不能重新创建节点，只能用上面的节点）
    col_start[0] = row_start[3];
    col_start[1] = row_start[1];
    col_start[2] = row_start[0];
    col_start[2]->col_next = row_start[3]->row_next;
    col_start[3] = row_start[0]->row_next;

    return 0;
}

/**
 * 后续通过 row_start 和 col_start 就可以访问矩阵非零元了
 * 十字链表就是为稀疏矩阵中的非零元建立行、列的链式关系
 */