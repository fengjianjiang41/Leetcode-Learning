#include "../common.h"
#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};

int main() {
    Solution s;
    int x;
    cin >> x;
    cout << s.mySqrt(x) << endl;
    return 0;
}