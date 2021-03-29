// author @1995YogeshSharma

// execute code online - https://leetcode.com/playground/L8EUJ2tZ

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; int right = height.size() - 1;
        
        int curArea;
        int maxArea = 0;
        
        int leftMoveArea, rightMoveArea;
        
        while (left < right) {
            curArea = min (height[left], height[right]) * (right - left); // w * h
            maxArea = max(maxArea, curArea);
            
            // decide whether to move left or right
            if (height[left] < height[right]) left++;
            else right--;
        }
        
        return maxArea;
    }
};

int main() {
    int n, temp;
    vector<int> heights;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        heights.push_back(temp);
    }
    Solution sol = Solution();
    cout << sol.maxArea(heights) << endl;
    return 0;
}
