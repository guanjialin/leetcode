//
// Created by addzero on 2020/11/30.
//


#include "header.h"

struct Trie
{
    struct Trie *elem[26];
    bool word;
};

struct Trie *trie_build(char **data, int size)
{
    struct Trie *trie = (struct Trie *) calloc(1, sizeof(struct Trie));

    for (int i = 0; i < size; ++i) {
        char *p = data[i];
        struct Trie *t = trie;

        while (*p != '\0') {
            if (NULL == t->elem[*p - 'a']) {
                t->elem[*p - 'a'] = (struct Trie *) calloc(1, sizeof(struct Trie));
            }
            t = t->elem[*p - 'a'];
            ++p;
        }
        t->word = true;
    }

    return trie;
}

char * replaceWords(char ** dictionary, int dictionarySize, char * sentence)
{
    struct Trie *trie = trie_build(dictionary, dictionarySize);
    int slow = 0, fast = 0;
    int size = strlen(sentence);
    char *ans = (char *) calloc(size + 1, sizeof(char));
    int index = 0;

    while (fast < size) {
        int cur = fast;
        struct Trie *t = trie;

        while (fast < size && sentence[fast] != ' '
            && t->elem[sentence[fast] - 'a'] != NULL && !t->elem[sentence[fast] - 'a']->word) {
            t = t->elem[sentence[fast] - 'a'];
            ++fast;
        }

        if (fast < size && sentence[fast] != ' '
            && t->elem[sentence[fast] - 'a'] != NULL && t->elem[sentence[fast] - 'a']->word) {
            while (cur <= fast) {
                ans[index++] = sentence[cur++];
            }
            while (fast < size && sentence[fast] != ' ') {
                ++fast;
            }
        } else {
            fast = cur;
            while (fast < size && sentence[fast] != ' ') {
                ans[index++] = sentence[fast++];
            }
        }
        ans[index++] = sentence[fast++];
    }

    return ans;
}

int main() {
    char **dict = (char **) alloca(3 * sizeof(char *));
    dict[0] = "cat"; dict[1] = "bat"; dict[2] = "rat";
    char sentence[] = "the cattle was rattled by the battery";
    printf("%s\n", replaceWords(dict, 3, sentence));

    return 0;
}