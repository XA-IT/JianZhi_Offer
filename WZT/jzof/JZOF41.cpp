

#include "stdafx.h"

class Solution {
public:
    void Insert(int num)
    {
        size_t min_len = min.size(), max_len = max.size();
        // 偶数先考虑存在最小堆中
        if (((min_len + max_len) & 1 ) == 0) {
            if (max_len > 0 && num < max.front()) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max.front();
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        } else {
            if (min_len > 0 && num > min.front()) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min.front();
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    { 
        size_t all_len = min.size() + max.size();
        if (all_len == 0)
            return 0;
        if ((all_len & 1) == 1)
            return min.front();
        else 
            return 0.5 * (max.front() + min.front());
    }
private:
    vector<int> min;        //最小堆
    vector<int> max;
};

int main() {
    Solution totest1;
    for (int i = 0; i < 10; i += 2) {
        totest1.Insert(i);
        cout << totest1.GetMedian() << endl;
    }
    return 0;
}