#include<iostream>
#include<stack>
#include<gtest/gtest.h>


using std::string;
using std::stack;

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> st;
        string str = "";
        
        for (int i=0; i < S.length(); i++) {
            if (!st.empty()) {
                if (st.top() == '(' && S[i] == ')') {
                    st.pop();
                } else {
                    st.push(S[i]);
                }
                if (!st.empty()) {
                    str.append(string(1,S[i]));
                    }
                } else {
                    st.push(S[i]);
                }
            }
        return str;
    }
};

