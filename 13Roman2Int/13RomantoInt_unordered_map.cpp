#include "../common.h"

class Solution {
private:
    unordered_map<char, int> symbolValues = { //how an unordered_map is init
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();  //how to find the length of a string
        for (int i = 0; i < n; i++){
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i+1]]){
                ans -= value;
            }
            else{
                ans += value;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    string test;
    cin >> test;
    cout << s.romanToInt(test) << endl;
    return 0;
}