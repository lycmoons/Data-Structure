#include<vector>
using namespace std;

// nums 为递增序列，target 为查找目标，返回值为目标在序列中的索引
int binarySearch(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}