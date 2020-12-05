//
// Created by addzero on 2020/12/5.
//


#ifdef __LOCAL__

#include "../header.h"

#endif

/*
 * C++ 不知道怎么存储 dequeue 的地址，还是用 C 吧
 * 不过C也太复杂了点。
 * 根据评论区大佬的写法，可实现均摊 O(1)
 */
enum {
    ANIMAL_CAT = 0,
    ANIMAL_DOG = 1,
};

enum {
    ANIMAL_ID = 0,
    ANIMAL_TYPE = 1,
};

struct d_list_node
{
    int val[2]; // val[0] -> 动物编号，val[1]->动物种类
    struct d_list_node *prev, *next;
};

struct list_node
{
    struct d_list_node *val;
    struct list_node *next, *prev;
};

typedef struct {
    struct d_list_node animals_head;       // 存储所有动物
    struct list_node dog_cat_head[2];      // [0] 存储猫，[1]存储狗
} AnimalShelf;


AnimalShelf* animalShelfCreate() {
    AnimalShelf *obj = (AnimalShelf *) calloc(1, sizeof(AnimalShelf));
    obj->animals_head.next = obj->animals_head.prev = &obj->animals_head;
    obj->dog_cat_head[ANIMAL_CAT].next = obj->dog_cat_head[ANIMAL_CAT].prev = &obj->dog_cat_head[ANIMAL_CAT];
    obj->dog_cat_head[ANIMAL_DOG].next = obj->dog_cat_head[ANIMAL_DOG].prev = &obj->dog_cat_head[ANIMAL_DOG];

    return obj;
}

void animalShelfEnqueue(AnimalShelf* obj, int* animal, int animalSize) {
    struct d_list_node *dnode = (struct d_list_node *) calloc(1, sizeof(struct d_list_node));
    memcpy(dnode->val, animal, sizeof(int) * 2);
    obj->animals_head.prev->next = dnode;
    dnode->prev = obj->animals_head.prev;
    dnode->next = &obj->animals_head;
    obj->animals_head.prev = dnode;

    struct list_node *node = (struct list_node *) calloc(1, sizeof(struct list_node));
    node->val = dnode;
    obj->dog_cat_head[animal[ANIMAL_TYPE]].prev->next = node;
    node->prev = obj->dog_cat_head[animal[ANIMAL_TYPE]].prev;
    node->next = &obj->dog_cat_head[animal[ANIMAL_TYPE]];
    obj->dog_cat_head[animal[ANIMAL_TYPE]].prev = node;
}

static int *dequeue(AnimalShelf *obj, int type)
{
    int *ans = (int *) calloc(2, sizeof(int));
    ans[0] = -1, ans[1] = -1;

    if (obj->dog_cat_head[type].next != &obj->dog_cat_head[type]) {
        struct list_node *node = obj->dog_cat_head[type].next;
        obj->dog_cat_head[type].next = node->next;
        node->next->prev = &obj->dog_cat_head[type];

        struct d_list_node *dnode = node->val;
        dnode->prev->next = dnode->next;
        dnode->next->prev = dnode->prev;

        ans[0] = dnode->val[ANIMAL_ID];
        ans[1] = dnode->val[ANIMAL_TYPE];

        free(node); node = NULL;
        free(dnode); dnode = NULL;
    }

    return ans;
}

int* animalShelfDequeueAny(AnimalShelf* obj, int* retSize) {
    int *ans = (int *) calloc(2, sizeof(int));
    ans[0] = -1, ans[1] = -1;
    *retSize = 2;

    if (obj->animals_head.next != &obj->animals_head) {
        struct d_list_node *node = obj->animals_head.next;
        return dequeue(obj, node->val[ANIMAL_TYPE]);
    }

    return ans;
}

int* animalShelfDequeueDog(AnimalShelf* obj, int* retSize) {
    *retSize = 2;
    return dequeue(obj, ANIMAL_DOG);
}

int* animalShelfDequeueCat(AnimalShelf* obj, int* retSize) {
    *retSize = 2;
    return dequeue(obj, ANIMAL_CAT);
}

void animalShelfFree(AnimalShelf* obj) {
    while (obj->animals_head.next != &obj->animals_head) {
        struct d_list_node *temp = obj->animals_head.next;
        obj->animals_head.next = temp->next;
        free(temp); temp = NULL;
    }

    while (obj->dog_cat_head[0].next != &obj->dog_cat_head[0]) {
        struct list_node *temp = obj->dog_cat_head[0].next;
        obj->dog_cat_head[0].next = temp->next;
        free(temp); temp = NULL;
    }

    while (obj->dog_cat_head[1].next != &obj->dog_cat_head[1]) {
        struct list_node *temp = obj->dog_cat_head[1].next;
        obj->dog_cat_head[1].next = temp->next;
        free(temp); temp = NULL;
    }

    free(obj);
}

/**
 * Your AnimalShelf struct will be instantiated and called as such:
 * AnimalShelf* obj = animalShelfCreate();
 * animalShelfEnqueue(obj, animal, animalSize);

 * int* param_2 = animalShelfDequeueAny(obj, retSize);

 * int* param_3 = animalShelfDequeueDog(obj, retSize);

 * int* param_4 = animalShelfDequeueCat(obj, retSize);

 * animalShelfFree(obj);
*/

#ifdef __LOCAL__

int main() {
    AnimalShelf *obj = animalShelfCreate();
    int data0[] = {0, 0};
    int data1[] = {1, 0};
    int ret = 0;
    animalShelfEnqueue(obj, data0, 2);
    animalShelfEnqueue(obj, data1, 2);
    animalShelfDequeueCat(obj, &ret);
    animalShelfDequeueDog(obj, &ret);
    animalShelfDequeueAny(obj, &ret);

    return 0;
}

#endif