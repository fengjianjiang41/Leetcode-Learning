#include "../common.h"

class Solution {
public:
    bool isValid(string s){
        int len = s.size();
        stack <char> stacks;
        if (len % 2 == 1) return false; //special cases
        else{
            for (int i = 0; i < len; ++i){
                char c = s[i];
                if (c == '(' || c == '{' || c == '[') stacks.push(c);
                else {
                    if (stacks.empty()) return false;
                    if (c == ')' && stacks.top() == '(') stacks.pop();
                    else if (c == ']' && stacks.top() == '[') stacks.pop();
                    else if (c == '}' && stacks.top() == '{') stacks.pop();
                    else return false;
                }
            }
            return stacks.empty() ? true : false;
        } 
    }
};

int main() {
    Solution s;
    string test;
    cin >> test;
    cout << s.isValid(test) << endl;
    return 0;
}