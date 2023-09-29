#include <iostream>
#include <vector>

using namespace std;

// 打印 vector 中的元素
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// 快速排序
void quick_sort(vector<int>& nums, int l, int r) {
    // 如果区间长度小于等于 1，直接返回
    if (l + 1 >= r) {
        return;
    }

    // 取第一个元素为关键字
    int first = l, last = r - 1, key = nums[first];

    // 两个指针从两端开始扫描，将小于关键字的元素放在左边，大于关键字的元素放在右边
    while (first < last) {
        while (first < last && nums[last] >= key) {
            --last;
        }
        nums[first] = nums[last];

        while (first < last && nums[first] <= key) {
            ++first;
        }
        nums[last] = nums[first];
    }

    // 将关键字放在中间
    nums[first] = key;

    // 递归排序左右两个区间
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}

int main() {
    vector<int> nums = {5, 2, 9, 1, 3};
    cout << "Original vector: ";
    printVector(nums);

    quick_sort(nums, 0, nums.size());

    cout << "Sorted vector: ";
    printVector(nums);

    return 0;
}