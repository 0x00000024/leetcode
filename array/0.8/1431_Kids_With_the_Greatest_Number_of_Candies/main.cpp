/*
Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of candies among them. Notice that multiple kids can have the greatest number of candies.



Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]
Explanation:
Kid 1 has 2 candies and if he or she receives all extra candies (3) will have 5 candies --- the greatest number of candies among the kids.
Kid 2 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.
Kid 3 has 5 candies and this is already the greatest number of candies among the kids.
Kid 4 has 1 candy and even if he or she receives all extra candies will only have 4 candies.
Kid 5 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false]
Explanation: There is only 1 extra candy, therefore only kid 1 will have the greatest number of candies among the kids regardless of who takes the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]


Constraints:

2 <= candies.length <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Time complexity O(n)
    // Space complexity O(n)
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        vector<bool> result;
        int maxValue = *max_element(candies.begin(), candies.end());
        cout << "test " << sizeof(maxValue) << " test";
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= maxValue) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};

int main() {
    vector<int> candies;
    string input;
    cout << "candies = ";
    getline(cin, input);

    int extraCandies;
    cout << "extraCandies = ";
    cin >> extraCandies;

    if (extraCandies < 1 || extraCandies > 50) {
        fprintf(stderr, "Constraints: 1 <= extraCandies <= 50");
        return -1;
    }

    stringstream ss(input);
    int n;
    while (ss >> n) {
        if (n < 1 || n > 100) {
            fprintf(stderr, "Constraints: 1 <= candies[i] <= 100");
            return -1;
        }
        candies.push_back(n);
    }

    if (candies.size() < 2 || candies.size() > 100) {
        fprintf(stderr, "Constraints: 2 <= candies.length <= 100");
        return -1;
    }

    Solution s;
    vector<bool> result;
    result = s.kidsWithCandies(candies, extraCandies);

    // Test
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
