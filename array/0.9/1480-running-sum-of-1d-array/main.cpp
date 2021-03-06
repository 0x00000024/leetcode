/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.



Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].


Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].


Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]


constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6

Time complexity O(N)
Space complexity O(1)
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

int main() {
    string input;
    getline(cin, input);
    vector<int> nums;

    stringstream ss(input);

    int n;
    while (ss >> n) {
        if (n < -pow(10, 6) || n > pow(10, 6)) {
            fprintf(stderr, "Constraints: -10^6 <= nums[i] <= 10^6");
            return -1;
        }
        nums.push_back(n);
    }

    if (nums.size() < 1 || nums.size() > 1000) {
        fprintf(stderr, "Constraints: 1 <= nums.length <= 1000");
        return -1;
    }

    Solution s;
    s.runningSum(nums);

    // Test
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}
