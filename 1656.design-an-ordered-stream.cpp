//
// Created by addzero on 2020/12/4.
//


#ifdef __LOCAL__
#include "cppheader.h"
#endif

class OrderedStream {
public:
    OrderedStream(int n) {
        streams.resize(n + 1);
    }

    vector<string> insert(int id, string value) {
        vector<string> ans;
        streams[id] = value;

        if (id == ptr) {
            while (ptr < streams.capacity() && !streams[ptr].empty()) {
                ans.emplace_back(streams[ptr]);
                ++ptr;
            }
        }

        return ans;
    }

private:
    vector<string> streams;
    int ptr = 1;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */

#ifdef __LOCAL__
int main()
{

    
    return 0;
}
#endif