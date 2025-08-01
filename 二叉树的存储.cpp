// 普通二叉树的存储（链式存储）
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int dt) {
        data = dt;
        left = nullptr;
        right = nullptr;
    }
};


// 完全二叉树的存储（顺序存储）
class BinaryTree {
private:
    vector<int> data;   // 一层一层顺序存储

public:
    // 获取当前二叉树节点数
    int size() {
        return data.size();
    }

    // 获取索引为 x 的节点的父节点的值
    int getParent(int x) {
        return data[(x - 1) / 2];
    }

    // 获取索引为 x 的节点的左孩子节点的值
    int getLeftChild(int x) {
        return data[2 * x + 1];
    }

    // 获取索引为 x 的节点的右孩子节点的值
    int getRightChild(int x) {
        return data[2 * x + 2];
    }

    // 获取索引为 x 的节点所在的层级（以根节点层级为第 0 层，往下递增）
    int getDepth(int x) {
        return int(log2(x + 1));
    }
};