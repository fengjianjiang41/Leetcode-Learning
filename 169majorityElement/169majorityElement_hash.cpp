#include "../common.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
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