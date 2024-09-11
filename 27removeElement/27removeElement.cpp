#include "../common.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int slow = 0;
        int fast = 0;
        int times = 0;
        while (fast < len) {
            if (nums[fast] == val) {
                times++;

            } else if (nums[fast] != val) {
                if (fast > slow)
                    nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return len - times;
    }
};

int main() {
    Solution s;
    vector<int> test;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i){
        int temp;
        cin >> temp;
        test.push_back(temp);
    }
    int val;
    cin >> val;
    cout << s.removeElement(test, val) << endl;
    for (int i = 0; i < test.size(); ++i){
        cout << test[i] << " ";
    }
    return 0;
}