// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。
// 它应该支持以下操作： 获取数据 get 和 写入数据 put 。

// 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，
// 则获取关键字的值（总是正数），否则返回 -1。
// 写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；
// 如果关键字不存在，则插入该组「关键字/值」。
// 当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
// 进阶:

// 你是否可以在 O(1) 时间复杂度内完成这两种操作？

// 示例:

// LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // 返回  1
// cache.put(3, 3);    // 该操作会使得关键字 2 作废
// cache.get(2);       // 返回 -1 (未找到)
// cache.put(4, 4);    // 该操作会使得关键字 1 作废
// cache.get(1);       // 返回 -1 (未找到)
// cache.get(3);       // 返回  3
// cache.get(4);       // 返回  4
// 通过次数81,043提交次数162,485

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/lru-cache
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include "../public_utils/public_utils.h"

struct DbLinkNode {
    int key, value;
    DbLinkNode *prev;
    DbLinkNode *next;
    DbLinkNode() : prev(NULL), next(NULL), key(0), value(0) {}
    DbLinkNode(int _key, int _value) : key(_key), value(_value),
                                       prev(NULL), next(NULL){};
};

class LRUCache {
private:
    int capacity_;
    int size;
    DbLinkNode *head;
    DbLinkNode *tail;
    unordered_map<int, DbLinkNode *> hsmp;

    void addToHead(DbLinkNode *curnode) {
        head->next->prev = curnode;
        curnode->next = head->next;
        curnode->prev = head;
        head->next = curnode;
        return;
    };

    void removeNode(DbLinkNode *curnode) {
        curnode->prev->next = curnode->next;
        curnode->next->prev = curnode->prev;
    }

    DbLinkNode *removeFromTail() {
        DbLinkNode *last = tail->prev;
        removeNode(last);
        return last;
    }

    void moveFront(DbLinkNode *cur) {
        removeNode(cur);
        addToHead(cur);
    };

public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        size = 0;
        head = new DbLinkNode();
        tail = new DbLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (hsmp.count(key) == 0)
            return -1;
        DbLinkNode *cur = hsmp[key];
        moveFront(cur);
        return cur->value;
    }
    
    void put(int key, int value) {
        DbLinkNode *cur = NULL;
        if (hsmp.count(key) == 0) {
            cur = new DbLinkNode(key, value);
            hsmp.insert(make_pair(key, cur));
            addToHead(cur);
            size++;
            if (size > capacity_) {
                DbLinkNode *last = removeFromTail();
                hsmp.erase(last->key);
                delete last;
                last = NULL;
                size--;
            }
        } else {
            cur = hsmp[key];
            cur->value = value;
            moveFront(cur);
        }
    }

    void showList() {
        DbLinkNode *cur = head->next;
        cout << "dblist: ";
        while (cur != tail) {
            cout << cur->key << ", " << cur->value << "; ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    LRUCache *obj = new LRUCache(3);
    vector<vector<int>> test = {
        {1, 1}, {2, 2}, {3, 3}, {4, 4}
    };
    int res = 0;
    for (int i = 0; i < test.size() * 2; i++) {
        if (i & 1) {
            res = obj->get(i / 2);
            obj->showList();
        } else {
            obj->put(test[i / 2][0], test[i / 2][1]);
            obj->showList();
        }
    }
    return 0;
}