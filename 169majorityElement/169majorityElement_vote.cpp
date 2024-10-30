#include "../common.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
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