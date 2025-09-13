#include<vector>
using namespace std;

/* 以下的排序算法按照升序举例 */

// 插入排序
/**
 * 认定前面的序列是已经排好序的序列
 * 依次将后面的每一个元素插入到前面的有序序列中
 */
void insertSort(vector<int>& nums) {
    // 初始认定 0 号元素是一个有序序列
    for(int i = 1; i < nums.size(); i++) {
        int value = nums[i];
        int temp = i - 1;
        while(temp >= 0 && nums[temp] > value) {
            nums[temp + 1] = nums[temp];
            temp--;
        }
        nums[temp + 1] = value;
    }
}


// 冒泡排序
/**
 * 从后面开始，元素之间两两比较
 * 将通过交换位置将最小的值交换到最前面
 * 此时最小值的位置已确定，然后用同样的方式找次小值
 */
void bubbleSort(vector<int>& nums) {
    // 只需要确定前 n - 1 个元素的位置，最后一个元素的位置就直接确定了
    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = nums.size() - 1; j > i; j--) {
            if(nums[j] < nums[j - 1]) {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
}


// 希尔排序
/**
 * 按照增量递减的顺序对不同分组的序列进行插入排序
 * 知道最终增量变为 1，对整个序列进行插入排序
 * 
 * 因为插入排序对于基本有序的序列的排序是很快的
 * 希尔排序的思想是一步一步将整个序列逐渐变有序
 */
void shellSort(vector<int>& nums) {
    // 初始增量设置为序列长度的一半，后续对增量进行二分，知道增量变为 1
    for(int delta = nums.size() / 2; delta >= 1; delta = delta / 2) {
        // 总共有 delta 个分组，对每个分组进行插入排序
        for(int i = 0; i < delta; i++) {
            // 插入排序
            for(int j = i + delta; j < nums.size(); j += delta) {
                int value = nums[j];
                int temp = j - delta;
                while(temp >= 0 && nums[temp] > value) {
                    nums[temp + delta] = nums[temp];
                    temp -= delta;
                }
                nums[temp + delta] = value;
            }
        }
    }
}


// 快速排序
/**
 * 初始选择一个基准元素，将整个序列调整为前后两个部分
 * 前部分序列元素小于基准元素
 * 后部分序列元素大于基准元素
 * 然后递归的去调整前后两个部分的序列
 * 直到被调整的序列中只有一个元素就退出递归
 */
void quickSort(vector<int>& nums, int low, int high) {
    if(low == high) return;

    // 每次调整使用序列的第一个元素作为基准元素
    int left = low;
    int right = high;
    int pivot = nums[left];
    while(left < right) {
        while(left < right && nums[right] >= pivot) right--;
        nums[left] = nums[right];
        while(left < right && nums[left] <= pivot) left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;

    quickSort(nums, low, left - 1);
    quickSort(nums, left + 1, high);
}


// 选择排序
/**
 * 将整个序列分为前后两个部分
 * 每次从后部分找到最小值尾接到前面的序列
 */
void selectSort(vector<int>& nums) {
    // 找到 n - 1 个最小值，剩下的那个值就确定是最大值了
    for(int i = 0; i < nums.size() - 1; i++) {
        int min_index = i;
        int min_value = nums[i];
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[j] < min_value) {
                min_index = j;
                min_value = nums[j];
            }
        }
        int temp = nums[i];
        nums[i] = min_value;
        nums[min_index] = temp;
    }
}


// 堆排序
/**
 * 将整个序列整理为一个大顶堆
 * 每次让堆顶元素与尾部元素交换，同时将堆的逻辑大小减一
 * 并向下调整根节点，保持大顶堆的特性
 * 直到堆的大小为 1
 */
void heapSort(vector<int>& nums) {
    // 将数组整理为堆（从最后一个非叶子节点开始往前面的节点遍历，分别进行向下调整）
    int size = nums.size();
    for(int i = size / 2 - 1; i >= 0; i--) {
        int index = i;
        while(true) {
            int left_index = 2 * index + 1;
            int right_index = 2 * index + 2;
            if(left_index > size - 1) break;
            int exchange_index = left_index;
            if(right_index <= size - 1 && nums[right_index] > nums[left_index]) exchange_index = right_index;
            if(nums[exchange_index] > nums[index]) {
                int temp = nums[index];
                nums[index] = nums[exchange_index];
                nums[exchange_index] = temp;
                index = exchange_index;
            }
            else break;
        }
    }

    // 在 size 变为 1 之前，每次将堆顶元素与尾部元素对换
    while(size > 1) {
        int temp = nums[0];
        nums[0] = nums[size - 1];
        nums[size - 1] = temp;
        size--;

        // 向下调整
        int index = 0;
        while(true) {
            int left_index = 2 * index + 1;
            int right_index = 2 * index + 2;
            if(left_index > size - 1) break;
            int exchange_index = left_index;
            if(right_index <= size - 1 && nums[right_index] > nums[left_index]) exchange_index = right_index;
            if(nums[exchange_index] > nums[index]) {
                int temp = nums[index];
                nums[index] = nums[exchange_index];
                nums[exchange_index] = temp;
                index = exchange_index;
            }
            else break;
        }
    }
} 


// 归并排序

// 基数排序

// 计数排序

// 外部排序