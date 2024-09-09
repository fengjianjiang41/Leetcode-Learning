#include "../common.h"

class Solution {
public:
    vector<int> twoSum (vector <int> & array, int const target){
        std::unordered_map <int, int> theOtherVal;
        for (int i = 0; i < array.size(); ++i){
            if (theOtherVal.count(array[i])){
                return {theOtherVal[array[i]], i};
            }
            int other = target - array[i];
            theOtherVal[other] = i;
        }
        throw invalid_argument("No two sum solution");
    }
};

int main(){
// use cin to input the test values of twoSum
    vector<int> inputArray;
    int target;
    cin >> target;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i){
        int temp;
        cin >> temp;
        inputArray.push_back(temp);
    }
    Solution s;
    vector<int> result = s.twoSum(inputArray, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}