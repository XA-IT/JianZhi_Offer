// �����������յ����ݽṹ����ƺ�ʵ��һ���0�2 LRU (�������ʹ��) ������ơ�
// ��Ӧ��֧�����²����� ��ȡ���� get �� д������ put ��

// ��ȡ���� get(key) - ����ؼ��� (key) �����ڻ����У�
// ���ȡ�ؼ��ֵ�ֵ�����������������򷵻� -1��
// д������ put(key, value) - ����ؼ����Ѿ����ڣ�����������ֵ��
// ����ؼ��ֲ����ڣ��������顸�ؼ���/ֵ����
// �����������ﵽ����ʱ����Ӧ����д��������֮ǰɾ�����δʹ�õ�����ֵ���Ӷ�Ϊ�µ�����ֵ�����ռ䡣
// ����:

// ���Ƿ�����ځ0�2O(1) ʱ�临�Ӷ�����������ֲ�����

// ʾ��:

// LRUCache cache = new LRUCache( 2 /* �������� */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // ����  1
// cache.put(3, 3);    // �ò�����ʹ�ùؼ��� 2 ����
// cache.get(2);       // ���� -1 (δ�ҵ�)
// cache.put(4, 4);    // �ò�����ʹ�ùؼ��� 1 ����
// cache.get(1);       // ���� -1 (δ�ҵ�)
// cache.get(3);       // ����  3
// cache.get(4);       // ����  4
// ͨ������81,043�ύ����162,485

// ��Դ�����ۣ�LeetCode��
// ���ӣ�https://leetcode-cn.com/problems/lru-cache
// ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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