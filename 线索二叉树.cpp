/**
 * 线索二叉树：
 * 对于一个有空指针域的节点，用其空指针与来指向其遍历序列的前驱和后继
 * 
 * 作用：
 * 对于一个随机给出的二叉树中的节点，找其遍历序列的前驱和后继不需要遍历整个二叉树
 * 空的左孩子指针指向该节点的遍历前驱
 * 空的右孩子指针指向该节点的遍历后继
 */

// 线索二叉树的节点设计
class Node {
public:
    int val;
    Node* left;
    Node* right;
    bool ltag;    // true 表示左指针指向左孩子，false 表示指向遍历前驱
    bool rtag;    // true 表示右指针指向右孩子，false 表示指向遍历后继
};



// 以中序遍历为例，设计二叉树的线索化
Node* pre = nullptr;

void visit(Node* node) {
    if(node->left == nullptr) {
        node->left = pre;
        node->ltag = false;
    }
    if(pre != nullptr && pre->right == nullptr) {
        pre->right = node;
        pre->rtag = false;
    }
    pre = node;
}

void inThread(Node* root) {
    if(root != nullptr) {
        inThread(root->left);
        visit(root);
        inThread(root->right);
    }
}

// 给最后一个节点添加后继线索
if(pre != nullptr && pre->right == nullptr) {
    pre->right = node;
    pre->rtag = false;
}