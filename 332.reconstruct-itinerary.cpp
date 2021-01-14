//
// Created by addzero on 2020/11/26.
//


#include "header/cppheader.h"


#ifdef __SELF__
// 自己的解法，还是答案解法更精辟
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        const string begin = "JFK";
        size = tickets.size() + 1;

        // 方便后续查找
        for (const auto &ticket : tickets) {
            map_ticket[ticket[0]].insert(ticket[1]);
        }
        ans.push_back(begin);
        dfs(begin);

        return ans;
    }

private:
    bool dfs(const string &begin)
    {
        if (map_ticket.find(begin) == map_ticket.end()
            || map_ticket[begin].empty()) {
            return ans.size() == size;
        }

        auto dsts = map_ticket[begin];
        for (const auto &dst : dsts) {
            ans.push_back(dst);
            map_ticket[begin].erase(map_ticket[begin].find(dst));
            if (dfs(dst)) {
                return true;
            }
            ans.pop_back();
            map_ticket[begin].insert(dst);
        }

        return false;
    }

private:
    int size;
    vector<string> ans;
    unordered_map<string, multiset<string>> map_ticket;
};
#else
// 答案解法：死胡同的入度和出度的差值必定为1
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        // 方便后续查找
        for (const auto &ticket : tickets) {
            map_ticket[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        std::reverse(ans.begin(), ans.end());

        return ans;
    }

private:
    void dfs(const string &begin)
    {
        while (map_ticket.count(begin) && map_ticket[begin].size() > 0) {
            string tmp = map_ticket[begin].top();
            map_ticket[begin].pop();
            dfs(tmp);
        }

        ans.emplace_back(begin);
    }

private:
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>, std::greater<>>> map_ticket;
};
#endif


int main() {
    vector<vector<string>> tickets = {
            {"MEL","PER"},{"SYD","CBR"},{"AUA","DRW"},{"JFK","EZE"},{"PER","AXA"},{"DRW","AUA"},{"EZE","SYD"},
            {"AUA","MEL"},{"DRW","AUA"},{"PER","ANU"},{"CBR","EZE"},{"EZE","PER"},{"MEL","EZE"},{"EZE","MEL"},
            {"EZE","TBI"},{"ADL","DRW"},{"ANU","EZE"},{"AXA","ADL"}
    };
    vector_print(Solution().findItinerary(tickets));

    return 0;
}