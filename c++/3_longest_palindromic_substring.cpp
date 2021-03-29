// author @1995YogeshSharma

// link to execute code online - https://leetcode.com/playground/fLkhtdEv

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getCurPalindrome(int curLen, string curStr, int left, int right, int len, string s) {
        while (left >= 0 && right < len && s[left] == s[right]) {
            curLen += 2;
            left--; right++;
        }
        return curLen;
    }
    
    string longestPalindrome(string s) {
        
        int maxLen = 0;
        string maxStr = "";
        
        int curlen1, curlen2;
        
        int len = s.length();
        int start, end;
        for (int i=0; i < len; i++) {
            // consider current index is center of odd length palindrome
            string temp="";
            curlen1 = getCurPalindrome(1, temp+s[i], i-1, i+1, len, s);
            if (curlen1 > maxLen) {
                start = i - (curlen1-1) / 2;
                end = i + (curlen1-1) / 2;
                maxLen = curlen1;
            }
            
            // consider current index is center of even length palindrome
            curlen2 = getCurPalindrome(0, "", i, i+1, len, s);
            if (curlen2 > maxLen) {
                start = i + 1 - curlen2 / 2;
                end = i + curlen2 / 2;
                maxLen = curlen2;
            }
            
        }
        
        return s.substr(start, end - start + 1); 
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol = Solution();

    cout << sol.longestPalindrome(s) << endl;
   
    return 0;
}
