#include "../common.h"

class Solution {
public:
    int mySqrt(int x) {
        int l = 0; int r = x; int ans = -1;
        while (l<=r){
            int mid = (l+r)/2;
            if ((long long)mid*mid<=x){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int x;
    cin >> x;
    cout << s.mySqrt(x) << endl;
    return 0;
}