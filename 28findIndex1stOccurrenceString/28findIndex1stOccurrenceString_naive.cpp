#include "../common.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        while (p1 >= -1 && p2 >= 0) {
            if (p1 == -1) {
                nums1[p1 + p2 + 1] = nums2[p2];
                p2--;
            } else if (nums2[p2] >= nums1[p1]) {
                nums1[p1 + p2 + 1] = nums2[p2];
                p2--;
            } else {
                nums1[p1 + p2 + 1] = nums1[p1];
                p1--;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> test1;
    vector<int> test2;
    int num1, num2;
    cin >> num1 >> num2;
    for (int i = 0; i < num1; ++i){
        int temp;
        cin >> temp;
        test1.push_back(temp);
    }
    for (int i = 0; i < num2; ++i){
        int temp;
        cin >> temp;
        test2.push_back(temp);
    }
    s.merge(test1, num1, test2, num2);
    for (int i = 0; i < test1.size(); ++i){
        cout << test1[i] << " ";
    }
    return 0;
}