#include "../common.h"

class Solution {
public:
    int climbStairs(int n) {
        int res=0;
        int p=0;
        int q=1;
        for (int i=1;i<n;i++){
            q=p+q;
            p=q-p;
        }
        res=p+q;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(2) << endl;
    cout << s.climbStairs(3) << endl;
    return 0;
}