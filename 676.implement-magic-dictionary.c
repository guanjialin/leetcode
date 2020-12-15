//
// Created by addzero on 2020/12/15.
//


#ifdef __LOCAL__
#include "header.h"
#endif

struct trie_node {
    bool word;
    struct trie_node *next[26];
};

typedef struct magic_dictionary {
    struct trie_node trie;
} MagicDictionary;

/** Initialize your data structure here. */

MagicDictionary* magicDictionaryCreate() {
    return (struct magic_dictionary *) calloc(1, sizeof(struct magic_dictionary));
}

static inline struct trie_node *trie_node_create()
{
    return (struct trie_node *) calloc(1, sizeof(struct trie_node));
}

void magicDictionaryBuildDict(MagicDictionary* obj, char ** dictionary, int dictionarySize) {
    for (int i = 0; i < dictionarySize; ++i) {
        char *p = dictionary[i];
        struct trie_node *trie = &obj->trie;

        while (*p != '\0') {
            if (!trie->next[*p - 'a']) {
                trie->next[*p - 'a'] = trie_node_create();
            }
            trie = trie->next[*p - 'a'];
            ++p;
        }
        trie->word = true;
    }
}

static bool search(const struct trie_node *trie, const char *word)
{
    if (!trie) {
        return false;
    }

    while (trie && *word) {
        if (!trie->next[*word - 'a']) {
            return false;
        }
        trie = trie->next[*word - 'a'];
        ++word;
    }

    return trie->word;
}

bool magicDictionarySearch(MagicDictionary* obj, char * searchWord) {
    struct trie_node *trie = &obj->trie;

    while (trie && *searchWord != '\0') {
        for (int i = 0; i < 26; ++i) {
            if (i != (*searchWord - 'a')
                && search(trie->next[i], searchWord + 1)) {
                return true;
            }
        }

        trie = trie->next[*searchWord - 'a'];
        ++searchWord;
    }

    return false;
}

void magicDictionaryFree(MagicDictionary* obj) {

}

/**
 * Your MagicDictionary struct will be instantiated and called as such:
 * MagicDictionary* obj = magicDictionaryCreate();
 * magicDictionaryBuildDict(obj, dictionary, dictionarySize);

 * bool param_2 = magicDictionarySearch(obj, searchWord);

 * magicDictionaryFree(obj);
*/

#ifdef __LOCAL__
int main()
{
    char **dict = (char **) malloc(3 * sizeof(char *));
    dict[0] = "hello"; dict[1] = "leetcode"; dict[2] = "hallo";
    MagicDictionary *magicDictionary = magicDictionaryCreate();
    magicDictionaryBuildDict(magicDictionary, dict, 3);
    printf("%d\n", magicDictionarySearch(magicDictionary, "hello"));
    printf("%d\n", magicDictionarySearch(magicDictionary, "hhllo"));
    printf("%d\n", magicDictionarySearch(magicDictionary, "hell"));
    printf("%d\n", magicDictionarySearch(magicDictionary, "leetcoded"));

    return 0;
}
#endif