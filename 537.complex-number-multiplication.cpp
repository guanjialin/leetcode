//
// Created by dell on 2020/11/1.
//

#include "header/cppheader.h"

#ifdef __cplusplus
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        auto val1 = resolve(a);
        auto val2 = resolve(b);

        return std::to_string(val1.first * val2.first - val1.second * val2.second) + "+"
            + std::to_string(val1.first * val2.second + val1.second * val2.first) + "i";
    }

private:
    static pair<int, int> resolve(const string &s) {
        pair<int, int> ans;

        auto iter = s.find('+');
        ans.first = atoi(s.substr(0, iter).c_str());
        ans.second = atoi(s.substr(iter + 1, s.find('i')).c_str());

        return ans;
    }
};
#else
char * complexNumberMultiply(char * a, char * b){
    int A, B, C, D;
    sscanf(a, "%d+%di", &A, &B);
    sscanf(b, "%d+%di", &C, &D);

    int real = A * C - B * D;
    int image = A * D + B * C;
    char *ans = (char *) calloc(16, sizeof(char));
    sprintf(ans, "%d+%di", real, image);

    return ans;
}
#endif

int main()
{
#ifdef __cplusplus
    cout << Solution().complexNumberMultiply("1+1i", "1+1i") << endl;
#else
    printf("%s", complexNumberMultiply("1+1i", "1+1i"));
#endif

    return 0;
}