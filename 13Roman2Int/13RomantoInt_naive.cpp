#include "../common.h"

class Solution {
private:
    int afterI (char i_, int & j) {
        if (i_ == 'V') {j++; return 4;}
        else if  (i_ == 'X') {j++; return 9;}
        else return 1;
    }
    
    int afterX (char x_, int & j) {
        if (x_ == 'L') {j++; return 40;}
        else if  (x_ == 'C') {j++; return 90;}
        else return 10;
    }
    
    int afterC (char c_, int & j) {
        if (c_ == 'D') {j++; return 400;}
        else if  (c_ == 'M') {j++; return 900;}
        else return 100;
    }

public:
    int romanToInt(string s) {
        int ans = 0;
        int len = s.length();
        for (int i = 0; i < len; i++){
            int add = 0;
            if (i == len - 1) {
                if (s[i] == 'I') add = 1; 
                if (s[i] == 'X') add = 10;
                if (s[i] == 'C') add = 100;
                if (s[i] == 'V') add = 5; 
                if (s[i] == 'L') add = 50;
                if (s[i] == 'D') add = 500;
                if (s[i] == 'M') add = 1000; 
            }
            else{
                if (s[i] == 'I') add = afterI(s[i + 1], i);
                else if (s[i] == 'X') add = afterX(s[i + 1], i);
                else if (s[i] == 'C') add = afterC(s[i + 1], i);
                else{
                    if (s[i] == 'V') add = 5; 
                    if (s[i] == 'L') add = 50;
                    if (s[i] == 'D') add = 500;
                    if (s[i] == 'M') add = 1000;                
                }
            }
            ans += add;
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