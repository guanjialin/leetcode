//
// Created by addzero on 2020/12/17.
//


#ifdef __LOCAL__
#include "header.h"
#endif

#if 0
// 双向链表 + hash 解法，官方解法更简洁，见下
struct list_value {
    int freq = 0;
    int key = 0;
    int value = 0;
    list_value() {};
    list_value(int _freq, int _key, int _value) : freq(_freq), key(_key), value(_value) {};
};

struct lfu_node {
    int freq;
    DoubleListNode<list_value> *keys = nullptr;   // first->freq, second->value;
    lfu_node(int val) : freq(val) {};
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        cache = new DoubleListNode<lfu_node *>;
        cache->prev = cache->next = cache;
    }

    int get(int key) {
        if (!keys.count(key)) {
            return -1;
        }

        put(key, keys[key]->val.value);
        return keys[key]->val.value;
    }

    void put(int key, int value) {
        if (!capacity) {
            return;
        }

        int freq = keys.count(key) ? keys[key]->val.freq + 1 : 1;
        size += keys.count(key) ? 0 : 1;

        // 先删除原来 freq 节点上的值
        auto before_freq = cache;
        if (keys.count(key)) {
            int freq_odd = keys[key]->val.freq;
            keys[key]->Remove();

            before_freq = frequencies[freq_odd];
            if (frequencies[freq_odd]->val->keys->Empty()) {
                before_freq = frequencies[freq_odd]->prev;
                frequencies[freq_odd]->Remove();
                frequencies.erase(freq - 1);
            }
        }

        if (size > capacity && !keys.count(key)) {
            keys.erase(cache->next->val->keys->next->val.key);
            cache->next->val->keys->next->Remove();
            if (cache->next->val->keys->Empty()) {
                frequencies.erase(cache->next->val->freq);
                cache->next->Remove();
            }
            --size;
        }

        // 如果主链没有 freq 对应的节点，则先创建并插入到主链上
        if (!frequencies.count(freq)) {
            auto node = new lfu_node(freq);
            node->keys = new DoubleListNode<list_value>();
            node->keys->prev = node->keys->next = node->keys;

            frequencies[freq] = before_freq->InsertAfter(node);
        }

        keys[key] = frequencies[freq]->val->keys->InsertBefore(list_value(freq, key, value));
    }

private:
    int size = 0;
    int capacity = 0;
    DoubleListNode<lfu_node *> *cache;  // 主链
    unordered_map<int, DoubleListNode<lfu_node *> *> frequencies;   // first->freq, second->node
    unordered_map<int, DoubleListNode<list_value> *> keys;    // first->key, second->node
};
#else
// 官方题解，更精辟
struct entry
{
    int key;
    int value;
    int freq;
    entry(int _key, int _value, int _freq) : key(_key), value(_value), freq(_freq) {};
};

class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!idx_tables.count(key)) {
            return -1;
        }
        put(key, (*idx_tables[key])->value);
        return (*idx_tables[key])->value;
    }

    void put(int key, int value) {
        if (!cap) {
            return;
        }

        if (idx_tables.count(key)) {    // 命中
            auto freq = (*idx_tables[key])->freq;
            // 先删除旧的freq上的节点。
            freq_tables[freq].erase(idx_tables[key]); // 这里已经把 item 释放掉了
            // 如果旧的freq上的链表已经没有节点，则直接删除链表
            if (freq_tables[freq].empty()) {
                freq_tables.erase(freq);
                min_freq += min_freq == freq;
            }

            // 插入到 freq + 1 的链表上
            freq_tables[freq + 1].push_front(new entry(key, value, freq + 1));
            idx_tables[key] = freq_tables[freq + 1].begin();
        } else {    // 未命中
            // 如果空间满了，则移除使用频率最小的
            if (idx_tables.size() == cap) {
                idx_tables.erase(freq_tables[min_freq].back()->key);
                freq_tables[min_freq].pop_back();
                if (freq_tables[min_freq].empty()) {
                    freq_tables.erase(min_freq);
                }
            }

            // 先插入
            freq_tables[1].push_front(new entry(key, value, 1));
            idx_tables[key] = freq_tables[1].begin();
            min_freq = 1;
        }
    }

private:
    int cap = 0;
    int min_freq = 0;
    unordered_map<int, list<entry *>> freq_tables;    // first -> freq, second -> entry;
    unordered_map<int, list<entry *>::iterator> idx_tables;
};
#endif

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#ifdef __LOCAL__
int main()
{
    LFUCache obj(2);
    cout << obj.get(1) << endl; // -1
    obj.put(1, 1);
    obj.put(2, 2);
    cout << obj.get(1) << endl; // 1
    obj.put(3, 3);
    cout << obj.get(2) << endl; // -1
    cout << obj.get(3) << endl; // 3    2:1,3
    obj.put(4, 4);
    cout << obj.get(1) << endl; // -1
    cout << obj.get(3) << endl; // 3    1:4; 3:3
    cout << obj.get(4) << endl; // 4

    return 0;
}
#endif