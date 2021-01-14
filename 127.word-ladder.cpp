//
// Created by addzero on 2020/11/5.
//


#include "header/cppheader.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step = 1;
        queue<string> queue_ladder;
        unordered_set<string> set_visited;
        unordered_set<string> set_word;

        for (const auto &word : wordList) {
            set_word.insert(word);
        }
        queue_ladder.push(beginWord);
        set_visited.insert(beginWord);

        while (!queue_ladder.empty()) {
            ++step;
            int qsize = queue_ladder.size();
            for (int i = 0; i < qsize; ++i) {
                string cur = queue_ladder.front();
                queue_ladder.pop();

                // 尝试替换单词的每一个位
                for (auto &c : cur) {
                    char origin = c;
                    for (char j = 'a'; j <= 'z'; ++j) {
                        c = j;

                        if (set_word.find(cur) != set_word.end()
                            && set_visited.find(cur) == set_visited.end()) {
                            if (cur == endWord) {
                                return step;
                            }

                            queue_ladder.push(cur);
                            set_visited.insert(cur);
                        }
                    }
                    c = origin;
                }
            }
        }

        return 0;
    }
};

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    cout << Solution().ladderLength("hit", "cog", wordList) << endl;

    return 0;
}