#include "../common.h"
#include <algorithm>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << s.majorityElement(nums) << endl;
    return 0;
}