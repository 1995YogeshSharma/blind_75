// author @1995YogeshSharma

// link to execute code - https://leetcode.com/playground/Zrci4X3A

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> present;
        
        int result = 0;
        int cur = 0;
        
        int startptr = 0;
        for (auto i: s) {
            if (present.find(i) != present.end()) {
                // the character is found
                while (present.find(i) != present.end()) {
                    present.erase(s[startptr]);
                    startptr++;
                    cur -= 1;
                }
            }
            cur += 1;
            present.insert(i);
            result = max(result, cur);
        }
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol = Solution();
    int result = sol.lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}
