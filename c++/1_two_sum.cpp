// author @1995YogeshSharma

// link to execute code - https://leetcode.com/playground/Z7UiZTpv
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> complements;
        
        for (int i = 0; i < nums.size(); i++) {
            if (complements.find(nums[i]) != complements.end()) {
                return vector<int> {i, complements[nums[i]]};
            }
            complements[target-nums[i]] = i;
        }
        
        return vector<int> {0, 0};
    }
};

int main() {

    int n, target, temp;
    vector<int> nums;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp; nums.push_back(temp);
    }
    cin >> target;

    Solution sol = Solution();
    for (auto i : sol.twoSum(nums, target)) cout << " " << i << " ";
    cout << endl;

    return 0;
}
