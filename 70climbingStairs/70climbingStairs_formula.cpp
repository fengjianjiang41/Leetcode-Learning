#include "../common.h"
#include <cmath>

class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)round(fibn / sqrt5);
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(2) << endl;
    cout << s.climbStairs(3) << endl;
    return 0;
}