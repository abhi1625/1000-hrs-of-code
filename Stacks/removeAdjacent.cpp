#include<iostream>
#include<stack>

using std::stack;
using std::string;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        string str="";
        for (int i=0; i<S.length(); i++) {
            if (!st.empty()) {
                if (st.top() == S[i]) {
                    st.pop();
                    str.pop_back();
                // The important step is to push in both the stack and the string
                } else {
                    str.push_back(S[i]);
                    st.push(S[i]);
                }
            } else {
                st.push(S[i]);
                str.push_back(S[i]);
            }
        }
        return str;
    }
};