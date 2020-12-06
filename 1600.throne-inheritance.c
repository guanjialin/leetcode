//
// Created by addzero on 2020/12/6.
//


#ifdef __LOCAL__

#include "header.h"

#endif

struct tree_node
{
    char *name;
    bool alive;
    struct tree_node *brother, *child, *last_child; // last_child 方便 birth
};

struct hash_entry
{
    char *key;
    struct tree_node *val;
    UT_hash_handle hh;
};

typedef struct {
    int count;  // 活着的人数，方便申请内存
    struct tree_node *kingdom;
    struct hash_entry *hash;
} ThroneInheritance;


static struct tree_node *create_person(struct hash_entry **hash, char *name) {
    struct tree_node *node = (struct tree_node *) calloc(1, sizeof(struct tree_node));
    node->name = name;
    node->alive = true;

    // 放进 hash
    struct hash_entry *entry = (struct hash_entry *) calloc(1, sizeof(struct hash_entry));
    entry->key = name;
    entry->val = node;
    HASH_ADD_STR(*hash, key, entry);

    return node;
}

ThroneInheritance* throneInheritanceCreate(char * kingName) {
    ThroneInheritance *obj = (ThroneInheritance *) calloc(1, sizeof(ThroneInheritance));
    obj->kingdom = create_person(&obj->hash, kingName);
    ++obj->count;

    return obj;
}

static struct tree_node *find_parent(struct hash_entry **hash, char *parent_name)
{
    struct hash_entry *entry;
    HASH_FIND_STR(*hash, parent_name, entry);
    return entry->val;
}

void throneInheritanceBirth(ThroneInheritance* obj, char * parentName, char * childName) {
    struct tree_node *node = find_parent(&obj->hash, parentName);

    if (!node->child) {
        node->child = create_person(&obj->hash, childName);
        node->last_child = node->child;
    } else {
        node->last_child->brother = create_person(&obj->hash, childName);
        node->last_child = node->last_child->brother;
    }
    ++obj->count;
}

void throneInheritanceDeath(ThroneInheritance* obj, char * name) {
    struct tree_node *node = find_parent(&obj->hash, name);
    node->alive = false;
    --obj->count;
}

// 前序遍历
static void order_helper(struct tree_node *tree, char **ans, int *size)
{
    if (!tree) {
        return;
    }

    if (tree->alive) {
        ans[(*size)++] = tree->name;
    }
    order_helper(tree->child, ans, size);
    order_helper(tree->brother, ans, size);
}

char ** throneInheritanceGetInheritanceOrder(ThroneInheritance* obj, int* retSize) {
    char **ans = (char **) calloc(obj->count, sizeof(char *));
    *retSize = 0;
    order_helper(obj->kingdom, ans, retSize);

    return ans;
}

void throneInheritanceFree(ThroneInheritance* obj) {

}

/**
 * Your ThroneInheritance struct will be instantiated and called as such:
 * ThroneInheritance* obj = throneInheritanceCreate(kingName);
 * throneInheritanceBirth(obj, parentName, childName);

 * throneInheritanceDeath(obj, name);

 * char ** param_3 = throneInheritanceGetInheritanceOrder(obj, retSize);

 * throneInheritanceFree(obj);
*/

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

#ifdef __LOCAL__

int main() {
    ThroneInheritance *obj = throneInheritanceCreate("king");
    int ret = 0;
    char **ans;
    throneInheritanceBirth(obj, "king", "logan");
    throneInheritanceBirth(obj, "logan", "hosea");
    throneInheritanceBirth(obj, "king", "leonard");
    throneInheritanceDeath(obj, "king");
    throneInheritanceBirth(obj, "logan", "carl");
    throneInheritanceDeath(obj, "hosea");
    ans = throneInheritanceGetInheritanceOrder(obj, &ret);
    array_str_print(ans, ret);

    return 0;
}

#endif