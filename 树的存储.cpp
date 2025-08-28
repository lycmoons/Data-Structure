#include<vector>
using namespace std;
/**
 * 双亲表示法（顺序存储）
 * 
 * 通过双亲树组来存储树
 * 优点：找一个节点的双亲节点很快
 * 缺点：找一个节点的孩子节点需要遍历树组中的所有节点
 * 
 * 双亲表示法也可以用来表示森林
 */
class Node {
public:
    int data;      // 本身节点的数据
    int parent;    // 父亲节点在双亲树组中的索引（⚠️⚠️⚠️重点注意⚠️⚠️⚠️）
};

// 用 Node 类型的数组来存储树或森林
// 对于没有父节点的节点 parent 值为 -1（一个树的根节点，森林有多个根节点）
class Tree {
public:
    int n;               // 节点个数
    vector<int> nodes;
};


/**
 * 孩子表示法（顺序存储 + 链式存储）
 * 
 * 顺序存储每一个节点，其中顺序存储部分的指针指向第一个孩子节点
 * 孩子节点由孩子的索引和指向下一个孩子节点的指针构成
 * 优点：找一个节点的孩子很快
 * 缺点：找一个节点的父亲很慢
 * 
 */
class ChildNode {
public:
    int index;               // 孩子节点在顺序存储中的索引
    ChildNode* nextChild;    // 与该孩子同一个父亲的下一个孩子
};

class TreeNode {
public:
    int data;                // 节点的数据
    ChildNode* firstChild;   // 节点的第一个孩子节点
};

class Tree {
public:
    vector<TreeNode> nodes;
    int n;              // 节点个数
    vector<int> roots;  // 根节点的索引，考虑到存储森林，使用 vector 容器来存储
};


/**
 * 孩子兄弟表示法（链式存储，转化成二叉树来存储树）
 * 左指针指向该节点的第一个孩子
 * 右指针指向与该节点同父的下一个兄弟
 * 
 * 在使用这个方法存储森林时，不同的树的根节点视为有相同父节点的兄弟（⚠️⚠️⚠️重点注意⚠️⚠️⚠️）
 * 
 * 这个表示法可以用来进行树或森林与二叉树之间的相互转换
 */
class Node {
public:
    int data;
    Node* firstChild;
    Node* nextBrother;
};