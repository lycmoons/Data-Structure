/**
 * 并查集是一种无序集合数据结构
 * 可以使用森林的数据结构来存储，森林中每一棵树上的节点同属于一个集合
 * 不同的树是不同的集合
 * 
 * 并查集需要实现的功能主要有查与并：
 *      查 -> 查询某个节点属于哪一个集合（使用表示这个集合的树的根节点来标志）
 *      并 -> 合并两个不同的集合（将两个不同的树合并到一起，变成一个新的树）
 * 
 * 存储方式：选用双亲数组的方式来存储，可以快速找到每一个节点所在树的根节点
 */

class Node {
public:
    int data;       // 节点数据
    int parent;     // 父节点在数组中的索引

    // 根节点的parent值为负数，其绝对值表示这棵树的节点数量
};

#define SIZE 100
class Union_Find_Set {
    Node nodes[SIZE];

    Union_Find_Set() {
        // 用户传入所有节点数据
    }

    // 初始化，将每一个节点都当作一个独立的集合
    void init() {
        for(int i = 0; i < SIZE; i++) {
            nodes[i].parent = -1;
        }
    }

    // 合并两个不同的结合，传入参数为两个集合的根节点在数组中的索引
    // 将小树并入大树，降低树到高度，降低查询复杂度
    void Union(int root1, int root2) {
        if(nodes[root1].parent > nodes[root2].parent) {
            nodes[root2].parent += nodes[root1].parent;
            nodes[root1].parent = root2;
        }
        else {
            nodes[root1].parent += nodes[root2].parent;
            nodes[root2].parent = root1;
        }
    }

    // 查找节点所属集合，传入节点在数组中的索引，返回根节点所在的索引
    // 通过压缩查找路径的方式，降低树的高度，降低下一次查询的复杂度
    int Find(int node) {
        int root = node;
        while(nodes[root].parent >= 0) {
            root = nodes[root].parent;
        }

        // 压缩路径 -> 将路径上所有的节点都直接与根节点相连
        while(node != root) {
            int temp = nodes[node].parent;
            nodes[node].parent = root;
            node = temp;
        }

        return root;
    }
};