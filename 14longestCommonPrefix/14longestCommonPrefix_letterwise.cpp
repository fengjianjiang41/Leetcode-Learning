#include "../common.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < count; ++j){
                if (strs[j][i] != c || i+1 > strs[j].size()) {
              //if (strs[j][i] != c || i == strs[j].size())
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    Solution s;
    vector<string> test;
    string temp;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i){
        cin >> temp;
        test.push_back(temp);
    }
    cout << s.longestCommonPrefix(test) << endl;
    return 0;
}