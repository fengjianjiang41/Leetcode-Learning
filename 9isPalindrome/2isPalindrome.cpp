#include "../common.h"

class Solution {
public:
    bool isPalindrome (int test) {
        int front = test; int back = 0;
        if (test < 0 || (test % 10 == 0 && test !=0)) return false;
        else {
            while (back < front) {
                back = back * 10 + front % 10 ;
                front /= 10;
            }
            if (front == back || front == back / 10) return true;
            
        }
        return false;
    }
};

int main() {
    Solution s;
// use cin to input test cases
    int test;
    cin >> test;
    cout << s.isPalindrome(test) << endl;
    return 0;
}