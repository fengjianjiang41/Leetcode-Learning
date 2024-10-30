#include "../common.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while (true) {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for (int num : nums)
                if (num == candidate)
                    ++count;
            if (count > nums.size() / 2)
                return candidate;
        }
        return -1;
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