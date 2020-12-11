//
// Created by addzero on 2020/12/11.
//


#ifdef __LOCAL__
#include "header.h"
#endif

class double_list_node
{
public:
    double_list_node() = default;;
    explicit double_list_node(int _val) : val(_val) {};
    void insert_after(int _val) {
        auto node = new double_list_node(_val);
        node->next = this->next;
        node->prev = this;
        node->next->prev = node;
        node->prev->next = node;
    }
    void erase() {
        if (this->val != 1) {
            this->prev->next = this->next;
            this->next->prev = this->prev;
            delete this;
        }
    }

public:
    int val = 0;
    unordered_set<string> keys;
    double_list_node *prev = this, *next = this;
};

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        head = new double_list_node();
        head->insert_after(1);
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(const string& key) {
        if (records.count(key)) {   // key 已经存在，则将该 key 移入到 value + 1 的节点中
            // 如果后面一个节点的 value 刚好等于当前 value + 1， 则直接插入到后面节点即可，否则需要创建新节点
            if (records[key]->next->val != records[key]->val + 1) {
                records[key]->insert_after(records[key]->val + 1);
            }

            records[key]->next->keys.insert(key);
            records[key]->keys.erase(key);

            auto next = records[key]->next;
            // 如果目前节点的已经没有 key 存在，则需要删除当前节点
            if (records[key]->keys.empty()) {
                records[key]->erase();
            }

            records[key] = next;
        } else {    // key 不存在，则插入到 value 为 1 的节点中
            head->next->keys.insert(key);
            records[key] = head->next;
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(const string& key) {
        if (!records.count(key)) {
            return;
        }

        if (1 == records[key]->val) {
            records[key]->keys.erase(key);
            records.erase(key);
        } else {
            if (records[key]->val - 1 != records[key]->prev->val) {
                records[key]->prev->insert_after(records[key]->val - 1);
            }

            records[key]->prev->keys.insert(key);
            records[key]->keys.erase(key);
            auto del = records[key];
            records[key] = records[key]->prev;

            if (del->keys.empty()) {
                del->erase();
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return head->prev->keys.empty() ? "" : *head->prev->keys.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return !head->next->keys.empty() ? *head->next->keys.begin()
            : head->next->next->keys.empty() ? "" : *head->next->next->keys.begin();
    }

private:
    double_list_node *head;  // 链表的节点按 value 从小到大串起来
    unordered_map<string, double_list_node *> records;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

#ifdef __LOCAL__
int main()
{
    auto *obj = new AllOne();
    cout << obj->getMaxKey() << endl;
    cout << obj->getMinKey() << endl;
    obj->inc("hello");
    obj->inc("goodbye");
    obj->inc("hello");
    obj->inc("hello");
    cout << obj->getMaxKey() << endl;
    cout << obj->getMinKey() << endl;
    obj->inc("leet");
    obj->inc("code");
    obj->inc("leet");
    obj->dec("hello");
    obj->inc("leet");
    obj->inc("code");
    cout << obj->getMaxKey() << endl;
    cout << obj->getMinKey() << endl;

    return 0;
}
#endif