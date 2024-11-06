#include "../common.h"
#include <unordered_set>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i])) {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums;
    int num;
    int k;
    cin >> num;
    cin >> k;
    for (int i = 0; i < num; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << s.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}