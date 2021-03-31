// author @1995YogeshSharma

// Link to execute online - https://leetcode.com/playground/NpnAJ8WN

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        
        for (auto i: s) {
            if (i == '(' or i == '{' or i == '[') brackets.push(i);
            
            else {
                if (brackets.size() == 0) return false;
                
                if (i == ')' and brackets.top() == '(') brackets.pop();
                else if (i == '}' and brackets.top() == '{') brackets.pop();
                else if (i == ']' and brackets.top() == '[') brackets.pop();
                else {
                    return false;
                }
            }
        }
        
        if (brackets.size() > 0) return false;
        else return true;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().isValid(s) << endl;
    return 0;
}
