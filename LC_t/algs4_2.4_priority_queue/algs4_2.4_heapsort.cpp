/**
 * �ѵ����Կ��Ա�֤���ڵ������������Ƚ�һ��������Ԫ�ع���һ���ѣ�heapify��
 * ���ֹ���ͨ�����������sink�³�������Ϊ��࣬����һ��ʼ���Բ�����Ҷ�ڵ��Ƿ�����ֻ�����N/2��Ԫ�ؼ���
 * ���״ι�����ɺ�ÿ�δӸ��ڵ�ȡ����Ԫ�ط��ڼ���Ķѵ�ĩβ��������Ӷ���ɾ��������������
 * ��Ϊ���ѣ���Ϊ�ǵݼ����У���֮Ϊ�ǵ�������
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
    int sz = nums.size() - 1; /* ��0��Ԫ�ز�ʹ�� */
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