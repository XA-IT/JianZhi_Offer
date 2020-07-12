/**
 * 堆的特性可以保证根节点的有序，因此首先将一半待排序的元素构造一个堆（heapify）
 * 这种构造通过从右向左的sink下沉操作更为简洁，并且一开始可以不关心叶节点是否有序，只需遍历N/2个元素即可
 * 当首次构造完成后，每次从根节点取出该元素放在激活的堆的末尾，并将其从堆中删除，则整体有序
 * 若为最大堆，则为非递减序列，反之为非递增序列
*/
#include "../public_utils.h"

template<typename T>
class heapSort {
public:
    static void sort(vector<T>&);

private:
    static void sink(vector<T>& a, int k, int N);
};

template<typename T>
void heapSort<T>::sort(vector<T>& nums)
{
    int sz = nums.size() - 1; /* 第0个元素不使用 */
    for (int k = sz / 2; k >= 1; k--)
        sink(nums, k, sz);
    while (sz > 1) {
        swap(nums[1], nums[sz--]);
        sink(nums, 1, sz);
    }
}


template<typename T>
void heapSort<T>::sink(vector<T>& nums, int k, int N)
{
    int ch = k * 2;
    while (ch <= N) {
        if (ch < N && nums[ch] < nums[ch + 1])
            ch++;
        if (nums[ch] <= nums[k])
            break;
        swap(nums[ch], nums[k]);
        k = ch;
    }
}

int main()
{
    vector<int> test = {1, 2, 4, 5, 7, 3, 19, 54, 32, 24, 123, 21, 33};
    cout << "test vec: ";
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;
    heapSort<int> hs;
    hs.sort(test);
    cout << "res: ";
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }
    cout << endl;
    return 0;
}