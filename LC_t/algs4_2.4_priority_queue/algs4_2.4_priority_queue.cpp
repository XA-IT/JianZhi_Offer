/**
 * ���ȶ���֧��ɾ�����Ԫ���Լ�����Ԫ�صĲ�����ͨ���ѿ�����logN���Ӷ���ʵ��
 * ����һ����ȫ����������˿���ͨ��������б�ʾ��
 * ������һ�ڵ�k�丸�ڵ���ӽڵ�����p = k / 2;
 * �� ch1 = k * 2, ch2 = k * 2 + 1;
 * �Զ��е�Ԫ�صĲ��������������β����
 * Ϊ��ά�ֶѵ����򻯣����ϸ���swim�����³���sink�����ֲ�����
 * ����½ڵ�ʱ����β����ӣ�������swim��
 * ɾ�����ڵ㣨���ڵ㣩ʱ����β��Ԫ�ؽ���λ��ɾ���������µ�ͷ������sink
*/

#include "../public_utils.h"
#define MAX_ITEMS_NUM 10

template<typename T>
class maxPQ {
private:
    pair<int, T> *arr;
    int N;
    int _capacity;
    void swim(int i);
    void sink(int i);
public:
    explicit maxPQ(int max);
    ~maxPQ() { delete[] arr; }

    void show() const;
    void insert(pair<int, T>);
    pair<int, T> delMax();
    bool isEmpty() const { return N == 0; }
    int size() const { return N; }
    int capacity() const { return _capacity; }
};

template<typename T>
maxPQ<T>::maxPQ(int max) : arr(new pair<int, T>[max + 1]()), N(0),
                           _capacity(max + 1)
{
    arr[0] = pair<int, T>(INT8_MIN, T());
}

template<typename T>
void maxPQ<T>::swim(int i)
{
    while (i > 1 && arr[i].first > arr[i / 2].first) {
        swap(arr[i], arr[i / 2]);
        i /= 2;
    }
}

template<typename T>
void maxPQ<T>::sink(int i)
{
    while (2 * i <= N) {
        int j = i * 2;
        if (j < N && arr[j].first < arr[j + 1].first)
            j++;
        if (arr[j].first < arr[i].first)
            break;
        swap(arr[i], arr[j]);
        i = j;
    }
}

template<typename T>
void maxPQ<T>::insert(pair<int, T> x)
{
    if (N == _capacity)
        return;
    arr[++N] = x;
    swim(N);
}

template<typename T>
pair<int, T> maxPQ<T>::delMax()
{
    pair<int, T> res;
    if (isEmpty())
        return res;
    swap(arr[N], arr[1]);
    res = arr[N];
    arr[N--] = pair<int, T> ();
    sink(1);
    return res;
}

template<typename T>
void maxPQ<T>::show() const
{
    cout << "N: " << N << ", arr: ";
    for (int i = 1; i <= N; i++)
        cout << arr[i].first << " ";
    cout << endl;
}

int main(int argc, char **argv) {
    const int M = MAX_ITEMS_NUM;
    vector<int> test = {1, 2, 4, 5, 7, 3, 19, 54, 32, 24, 123, 21, 33};
    maxPQ<int> pq(M);
    for (int i = 0; i < test.size(); i++) {
        cout << "insert new item: " << test[i] << endl;
        if (i >= M) {
            pq.delMax();
        }
        pq.insert({test[i], test[i]});
        pq.show();
    }
    while (pq.isEmpty() == false) {
        pq.show();
        pq.delMax();
    }
    return 0;
}