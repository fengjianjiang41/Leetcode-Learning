#include "../common.h"
#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

int main() {
    Solution s;
    int x;
    cin >> x;
    cout << s.mySqrt(x) << endl;
    return 0;
}