#include "../common.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = strs.size();
        if (!count){
            return "";
        }
        string prefix = strs[0];
        for (int i = 1; i < count; ++i){
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()){
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string& str1, const string& str2){ 
    //overloading
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]){
            ++index;
        }
        return str1.substr(0, index);
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