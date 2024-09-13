#include "../common.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int head = 0;
        int tail = len - 1;
        int mid = (head + tail) / 2;
        while (tail - head > 1) {
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                head = mid;
            } else {
                tail = mid;
            }
            mid = (head + tail) / 2;
        }
        if (target<=nums[head]){
            return head;
        }else if (target<=nums[tail]){
            return tail;
        }else{
            return tail+1;
        }
    }
};

int main() {
    Solution s;
    vector<int> test;
    int num, target;
    cin >> num >> target;
    for (int i = 0; i < num; ++i){
        int temp;
        cin >> temp;
        test.push_back(temp);
    }
    cout << s.searchInsert(test, target);
    return 0;
}