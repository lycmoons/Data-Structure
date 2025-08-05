// 二叉树存储形式采用链式存储
class Node {
public:
    int val;
    Node* left;
    Node* right;
};


// 先序遍历（根左右）
void preOrder(Node* root) {
    if(root != nullptr) {
        // 访问 root 节点
        // ...
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历（左根右）
void inOrder(Node* root) {
    if(root != nullptr) {
        inOrder(root->left);
        // 访问 root 节点
        // ...
        inOrder(root->right);
    }
}

// 后序遍历（左右根）
void postOrder(Node* root) {
    if(root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        // 访问 root 节点
        // ...
    }
}

// 层次遍历
void levelOrder(Node* root) {
    if(root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        // 访问 temp 节点
        // ...
        if(temp->left != nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);
    }
}