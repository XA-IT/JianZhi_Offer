// 239. �����������ֵ
// ����һ������ nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��

// ���ػ��������е����ֵ��


// ���ף�

// ����������ʱ�临�Ӷ��ڽ��������


// ʾ��:

// ����: nums = [1,3,-1,-3,5,3,6,7], �� k = 3
// ���: [3,3,5,5,6,7] 
// ����: 

//   �������ڵ�λ��                ���ֵ
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3        3 1 -1 -3 5
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// ��ʾ��
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
// 1 <= k <= nums.length
// ͨ������58,254�ύ����120,988

#include "../public_utils/public_utils.h"

class Solution {
private:
    deque<int> dq;
    // ͨ������һ��˫�˶��У�ά�ֶ����е�Ԫ�� 1���ڴ��ڷ�Χ�ڣ�2�����ڵ���nums[i]
    // �Ժ�ÿ��������ǰ��Ԫ�ؼ�Ϊ�����е����Ԫ��
    // ˫�˶��еĵ���ʱ���Ͼ�
    void cleanDq(vector<int>& nums, int i, int k) {
        if (dq.empty() == false && dq.front() == i - k) {
            dq.pop_front();
        }
        while (dq.empty() == false && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        if (sz * k == 0) return { };
        if (k == 1) return nums;
        int i = 0, maxIdx = 0;
        vector<int> ret(sz - k + 1);
        for (; i < k; i++) {
            cleanDq(nums, i, k);
            dq.push_back(i);
            if (nums[dq.front()] > nums[maxIdx]) maxIdx = dq.front();
        }
        ret[0] = nums[maxIdx];
        for (; i < sz; i++) {
            cleanDq(nums, i, k);
            dq.push_back(i);
            ret[i - k + 1] = nums[dq.front()];
        }
        return ret;
    }
};

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{1, 3, -1, -3, 5, 3, 6, 7}, 3}
    };
    vector<vector<int>> expects = {
        {3, 3, 5, 5, 6, 7}
    };
    Solution sol;
    for (pair<vector<int>, int> test : tests) {
        vector<int> ret = sol.maxSlidingWindow(test.first, test.second);
        for (int num : ret) {
            cout << num << " ";
        }
        cout << endl;
    }
    for (vector<int> expectVec : expects) {
        for (int num : expectVec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}