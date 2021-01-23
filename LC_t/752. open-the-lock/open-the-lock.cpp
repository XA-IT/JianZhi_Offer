// 752. 打开转盘锁
// 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
// 每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

// 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

// 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

// 字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

// 示例 1:

// 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// 输出：6
// 解释：
// 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
// 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
// 因为当拨动到 "0102" 时这个锁就会被锁定。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/open-the-lock
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include "../public_utils/public_utils.h"

class Solution {
    int openLockCore(set<int> &deadends, unordered_map<int, int> &reached, int target, int cur, int count) {
        if (reached.count(cur) != 0) {
            return reached[cur];
        }
        if (deadends.count(cur) != 0) {
            return -1;
        }
        int multi = 1000;
        for (int i = 0; i < 4; i++) {
            
        }
    }
    int getInt(string str) {
        int tmp = 0;
        int multi = 1000;
        for (int j = 0; j < 4; j++) {
            tmp += (str[j] - '0') * multi;
            multi /= 10;
        }
        return tmp;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        set<int> deadendsSet;
        unordered_map<int, int> reached;
        for (int i = 0; i < deadends.size(); i++) {
            deadendsSet.insert(getInt(deadends[i]));
        }
        int ret;
        ret = openLockCore(deadendsSet, reached, getInt(target), 0, 0);
        return ret;
    }
};


int main() {
    vector<pair<vector<string>, string>> tests = {
        {
            {"0201","0101","0102","1212","2002"}, "0202"
        }
    };
    Solution sol;
    for (auto test : tests) {
        cout << "test begin, target: " << test.second << endl;
        cout << sol.openLock(test.first, test.second) << endl;
    }
    return 0;
}