/**
 * 二叉排序树的特性：
 *      树中每个节点的值互不相等
 *      每个节点的值都大于其左子树中任意节点的值
 *      每个节点的值都小于其右子树中任意节点的值
 * 
 * 二叉排序树的操作：
 *      1.查找
 *      2.插入
 *      3.删除（⚠️⚠️⚠️重点注意⚠️⚠️⚠️）
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};


// 1.查找操作，返回找到的节点指针
Node* search(Node* root, int target) {
    while(root != nullptr) {
        if(root->val == target) return root;
        else if(root->val < target) root = root->right;
        else root = root->left;
    }
    return nullptr;
}


// 2.插入操作
bool insert(Node*& root, int newVal) {
    if(root == nullptr) {
        root = new Node(newVal);
        return true;
    }
    else {
        Node* temp = root;
        while(true) {
            if(temp->val = newVal) return false;    // 树中不能有相同的值
            else if(temp->val > newVal) {
                if(temp->left == nullptr) {
                    temp->left = new Node(newVal);
                    return true;
                }
                temp = temp->left;
            }
            else {
                if(temp->right == nullptr) {
                    temp->right = new Node(newVal);
                    return true;
                }
                temp = temp->right;
            }
        }
    }
}


// TODO 3.删除操作
bool drop(Node*& root, int target) {
    Node* tar = search(root, target);
    if(tar == nullptr) return false;

    // 若需要删除的节点是根节点（特判）
    if(tar == root) {
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr && root->right != nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->left != nullptr && root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            // 选择使用右子树中的最小值代替 root 节点的值，然后删除右子树中的最小值
            Node* temp = root->right;
            Node* temp_father = root;
            while(temp->left != nullptr) {
                temp_father = temp;
                temp = temp->left;
            }
            root->val = temp->val;
            if(temp_father == root) root->right = temp->right;
            else temp_father->left = temp->right;
            delete temp;
        }

        return true;
    }

    // 当需要删除的顶点不是 root 节点时
    if(tar->left == nu)
}