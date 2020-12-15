//
// Created by addzero on 2020/12/15.
//


#ifdef __LOCAL__

#include "header.h"

#endif

static int cmp(const void *x, const void *y)
{
    return strcmp(*(char **) x, *(char **) y);
}

char * longestWord(char ** words, int wordsSize){
    int max_len = 0;
    char *ans = "";
    qsort(words, wordsSize, sizeof(char *), cmp);

    struct trie_node *trie = (struct trie_node *) calloc(1, sizeof(struct trie_node));
    struct trie_node *pt = trie;
    trie->word = true;

    struct trie_node *prev;
    for (int i = 0; i < wordsSize; ++i) {
        char *p = words[i];
        pt = trie;

        while (*p != '\0') {
            if (!pt->next[*p - 'a']) {
                pt->next[*p - 'a'] = trie_node_create();
            }
            prev = pt;
            pt = pt->next[*p - 'a'];
            ++p;
        }
        pt->word = prev->word;
        if (prev->word && strlen(words[i]) > max_len) {
            max_len = strlen(words[i]);
            ans = words[i];
        }
    }

    return ans;
}

#ifdef __LOCAL__

int main() {
    char **p = (char **) calloc(5, sizeof(char *));
    p[0] = "eyj"; p[1] = "e"; p[2] = "ey"; p[3] = "v"; p[4] = "vuq";
    printf("%s\n", longestWord(p, 5));

    return 0;
}

#endif