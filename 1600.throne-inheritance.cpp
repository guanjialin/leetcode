//
// Created by addzero on 2020/12/6.
//


#ifdef __LOCAL__
#include "cppheader.h"
#endif

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        king = kingName;
        kingdom[kingName] = vector<string>();
    }

    void birth(string parentName, string childName) {
        kingdom[parentName].push_back(childName);
    }

    void death(string name) {
        filter.insert(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        helper(ans, king);
        return ans;
    }

private:
    void helper(vector<string> &ans, const string& name)
    {
        if (!filter.count(name)) {
            ans.emplace_back(name);
        }

        for (const auto &child : kingdom[name]) {
            helper(ans, child);
        }
    }

private:
    unordered_map<string, vector<string>> kingdom;   // key 为父亲名字，value 为所有孩子
    unordered_set<string> filter;   // 存储已经死亡的
    string king;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

#ifdef __LOCAL__
int main()
{
    ThroneInheritance t("king");
    t.birth("king", "andy"); // 继承顺序：king > andy
    t.birth("king", "bob"); // 继承顺序：king > andy > bob
    t.birth("king", "catherine"); // 继承顺序：king > andy > bob > catherine
    t.birth("andy", "matthew"); // 继承顺序：king > andy > matthew > bob > catherine
    t.birth("bob", "alex"); // 继承顺序：king > andy > matthew > bob > alex > catherine
    t.birth("bob", "asha"); // 继承顺序：king > andy > matthew > bob > alex > asha > catherine
    vector_print(t.getInheritanceOrder()); // 返回 ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
    t.death("bob"); // 继承顺序：king > andy > matthew > bob（已经去世）> alex > asha > catherine
    vector_print(t.getInheritanceOrder()); // 返回 ["king", "andy", "matthew", "alex", "asha", "catherine"]
    
    return 0;
}
#endif