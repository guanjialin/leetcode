//
// Created by addzero on 2020/11/5.
//


#include "header/cppheader.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        bool running = true;

        for (const auto &word : wordList) {
            set_word.insert(word);
        }
        queue_ladder.push(beginWord);
        set_visited.insert(beginWord);

        while (!queue_ladder.empty() && running) {
            int qsize = queue_ladder.size();
            unordered_set<string> level;

            for (int i = 0; i < qsize; ++i) {
                string cur = queue_ladder.front();
                queue_ladder.pop();

                // 尝试替换单词的每一个位
                if (process_everyone(cur, endWord, level)) {
                    running = false;
                }
            }
        }

        if (!running) {
            find_path(endWord, vector<string>{endWord});
        }

        return ans;
    }

private:
    bool process_everyone(string s, const string& endWord, unordered_set<string> &level) {
        string origin = s;

        for (auto &c : s) {
            char temp = c;
            for (char j = 'a'; j <= 'z'; ++j) {
                c = j;

                if (set_word.find(s) != set_word.end()
                    && (level.find(s) != level.end() || set_visited.find(s) == set_visited.end())) {
                    map_path[s].insert(origin);
                    level.insert(s);
                    if (s == endWord) {
                        return true;;
                    }

                    queue_ladder.push(s);
                    set_visited.insert(s);
                }
            }
            c = temp;
        }

        return false;
    }

    void find_path(const string &word, vector<string> path) {
        if (map_path.find(word) == map_path.end()) {
            std::reverse(path.begin(), path.end());
            ans.push_back(path);
            return;
        }

        for (const auto& parent : map_path[word]) {
            path.push_back(parent);
            find_path(parent, path);
            path.pop_back();
        }
    }

private:
    vector<vector<string>> ans;
    queue<string> queue_ladder;
    unordered_set<string> set_visited;
    unordered_set<string> set_word;
    unordered_map<string, unordered_set<string>> map_path;
};

int main() {
    vector<string> wordList = {"hot","cog","dog","tot","hog","hop","pot","dot"};
    auto ans = Solution().findLadders("hot", "dog", wordList);
    for (auto vec : ans) {
        for (auto v : vec) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}