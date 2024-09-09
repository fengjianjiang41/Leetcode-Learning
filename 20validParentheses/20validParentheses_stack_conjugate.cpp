#include "../common.h"

class Solution {
public:
    bool isValid(string s) {
        if (s.size()%2 == 1) return false;
        stack<char> stacks;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                stacks.push(')');
            } else if (c == '[') {
                stacks.push(']');
            } else if (c == '{') stacks.push('}');
            else if (c == ')' || c == ']' || c == '}') {
                if (stacks.empty() || c != stacks.top()) return false;
                stacks.pop();
            }
        }
        return stacks.empty() ? true : false;
    }
};

int main() {
    Solution s;
    string test;
    cin >> test;
    cout << s.isValid(test) << endl;
    return 0;
}