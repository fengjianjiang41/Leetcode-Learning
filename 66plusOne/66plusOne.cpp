#include "../common.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                for (int j = i + 1; j < n; j++) {
                    digits[j] = 0;
                }
                return digits;
            }
        }
        vector<int> new_digits(n + 1);
        new_digits[0] = 1;
        return new_digits;
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
    vector<int> result = s.plusOne(test);
    for (int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    return 0;
}