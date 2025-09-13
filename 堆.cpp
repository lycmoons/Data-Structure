/**
 * 堆的实质是一个连续存储的二叉树
 * 也就是一个数组，其中数组中没有空值
 * 
 * 大顶堆：二叉树的任意一个节点都满足其左右子树中任意节点值都小于其值
 * 小顶堆：二叉树的任意一个节点都满足其左右子树中任意节点值都大于其值
 * 
 * 从 0 开始编号的堆的性质：
 *      i 号节点的左孩子是 2i + 1 号节点
 *      i 号节点的右孩子是 2i + 2 号节点
 *      i 号节点的父节点是 (i - 1) / 2 号节点
 *      最尾部的非叶子节点是 n / 2 - 1 号节点（总共有 n 个节点，编号为 0 ~ n - 1）
 */

// 以小顶堆为例
class Heap {
private:
    int bt[100];
    int size;

public:
    Heap() {
        size = 0;
    }

    // 插入新元素
    void push(int value) {
        // 先添加在尾部
        bt[size] = value;
        size++;
        
        // 再向上调整
        int temp = size - 1;
        while(temp != 0) {
            if(bt[(temp - 1) / 2] > value) {
                bt[temp] = bt[(temp - 1) / 2];
                temp = (temp - 1) / 2;
                bt[temp] = value;
            }
            else break;
        }
    }

    // 删除某个索引的元素
    void erase(int index) {
        // 将尾部元素放到删除的位置覆盖
        bt[index] = bt[size - 1];
        size--;

        // 再向下调整
        while(true) {
            int left_index = 2 * index + 1;
            int right_index = 2 * index + 2;
            if(left_index > size - 1) break;
            int exchange_index = left_index;
            if(right_index <= size - 1 && bt[right_index] < bt[left_index]) exchange_index = right_index;
            if(bt[exchange_index] < bt[index]) {
                int temp = bt[index];
                bt[index] = bt[exchange_index];
                bt[exchange_index] = temp;
                index = exchange_index;
            }
            else break;
        }
    }
};