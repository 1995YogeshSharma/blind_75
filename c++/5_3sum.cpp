// author @1995YogeshSharma

// link to execute code - https://leetcode.com/playground/BpU5CnHK

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        vector<vector<int>> result;
        
        set<vector<int>> bucket;
        
        for (int i = 0; i < size; i++) {
            int numToFind = -1 * nums[i];
            
            int left = i+1; int right = size-1;
            while (left < right) {
                if (nums[left] + nums[right] == numToFind) {
                    bucket.insert(vector<int> ({nums[i], nums[left], nums[right]}));
                    while (left < size-1 && nums[++left] == nums[left-1]);
                } else if (nums[left] + nums[right] < numToFind) {
                    while (left < size-1 && nums[++left] == nums[left-1]);
                } else {
                    while (right > 0 && nums[--right] == nums[right+1]);
                }
            }
        }
        
        for (auto i : bucket) result.push_back(i);
        
        return result;
    }
};

int main() {
    vector <int> nums; int n; int temp;
    cin >> n;
    while (n--) {
        cin >> temp; nums.push_back(temp);
    }

    vector<vector<int>> result;
    result = Solution().threeSum(nums);

    for (auto i: result) {
        for (auto j: i) {
            cout << " " << j << " ";
        }
        cout << endl;
    }

    return 0;
}
