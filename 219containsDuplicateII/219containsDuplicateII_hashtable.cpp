#include "../common.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>dictionary;
        int length=nums.size();
        for (int i=0;i<length;i++){
            int num =nums[i];
            if (dictionary.count(num)&&i-dictionary[num]<=k){
                return true;
            }
            dictionary[num]=i;
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
    for (int i = 0; i < num; ++i){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << s.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}