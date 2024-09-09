#include "../common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) { 
        int slow = 0; 
        int len = nums.size();
        for (int fast = 1; fast<len;fast++){
            if (nums[fast]>nums[slow]){
                slow++;
                if (fast > slow) nums[slow]=nums[fast];
            }
        }
        return slow+1;
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
    cout << s.removeDuplicates(test) << endl;
    for (int i = 0; i < test.size(); ++i){
        cout << test[i] << " ";
    }
    return 0;
}