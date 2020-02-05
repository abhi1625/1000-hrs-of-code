#include<iostream>
#include<stack>

using std::stack;
using std::string;

class Solution {
public:
    bool isValid(string s) {
        stack<char> paranthesis;
        bool valid = false;
        for (int i=0; i<s.length(); i++) {
            if (!paranthesis.empty()) {
                if (s[i] == '}' && paranthesis.top() == '{') {
                    paranthesis.pop();
                } else if (s[i] == ']' && paranthesis.top() == '[') {
                    paranthesis.pop();
                } else if (s[i] == ')' && paranthesis.top() == '(') {
                    paranthesis.pop();
                } else {
                    paranthesis.push(s[i]);
                }
            } else {
                paranthesis.push(s[i]);
            }
        }
        if (paranthesis.empty()) {
            valid = true;
        } else {
            valid =  false;
        }
        return valid;
    }
};