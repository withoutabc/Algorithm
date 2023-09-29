#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &nums, int n) {
    for (int i = 0; i < n; ++i) { // 外层循环，从第一个元素开始，到最后一个元素结束
        for (int j = i; j > 0 && nums[j] < nums[j-1]; --j) { // 内层循环，将当前元素插入到已排序的序列中
            swap(nums[j], nums[j-1]); // 如果当前元素小于前一个元素，则交换两个元素的位置
        }
    }
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = nums.size();
    insertion_sort(nums, n);
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
从第一个元素开始，该元素可以认为已经被排序
取出下一个元素，在已经排序的元素序列中从后向前扫描
如果该元素（已排序）大于新元素，将该元素移到下一位置
重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
将新元素插入到该位置后
重复步骤2~5
*/