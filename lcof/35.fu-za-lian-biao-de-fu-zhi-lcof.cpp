//
// Created by dell on 2020/10/20.
//

#include "../cppheader.h"

#ifdef __RECURSION__
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }

        if (umap.find(head) != umap.end()) {
            return umap[head];
        }

        Node *node = new Node(head->val);
        umap[head] = node;
        node->random = copyRandomList(head->random);
        node->next = copyRandomList(head->next);

        return node;
    }

private:
    std::unordered_map<Node *, Node *> umap;
};
#else
class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) {
            return NULL;
        }

        Node *p = head;

        // 复制节点
        while (p) {
            Node *node = new Node(p->val);
            node->next = p->next;
            p->next = node;
            p = p->next->next;
        }

        // 修改 random 指针
        p = head;
        Node *q = head->next;
        while (q) {
            q->random = p->random ? p->random->next : NULL;
            p = q->next;
            q = p ? p->next : NULL;
        }

        // 修改 next 指针
        Node *ans = head->next;
        q = head->next;
        p = head;
        while (q) {
            p->next = q->next;
            q->next = q->next ? q->next->next : NULL;
            q = q->next;
            p = p->next;
        }

        return ans;
    }
};
#endif

int main()
{
    Node node1 = Node(1),
         node2 = Node(2);

    node1.next = &node2;
    node1.random = &node2;
    node2.next = NULL;
    node2.random = &node2;

    Node *node = Solution().copyRandomList(&node1);
    while (node) {
        std::cout << node->val << ", " << node->random->val << std::endl;
        node = node->next;
    }

    Node *p = &node1;
    while (p) {
        std::cout << p->val << ", " << p->random->val << std::endl;
        p = p->next;
    }

    return 0;
}