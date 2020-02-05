#include <stack>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::stack;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> curr_valid_score;
        stack<int> prev_valid_score;
        int sum=0;
        
        for (auto curr_str : ops) {
            if (!curr_valid_score.empty()) {
                if (curr_str == "+") {
                   if (!prev_valid_score.empty()) {
                                    int new_valid_score = curr_valid_score.top() + prev_valid_score.top();
                                prev_valid_score.push(curr_valid_score.top());
                                curr_valid_score.push(new_valid_score);
                                }
                } else if (curr_str == "C") {
                    if (!prev_valid_score.empty()) {
                        prev_valid_score.pop();
                    }
                    curr_valid_score.pop();
                } else if (curr_str == "D") {
                    prev_valid_score.push(curr_valid_score.top());
                    curr_valid_score.push(2*curr_valid_score.top());
                } else {
                    prev_valid_score.push(curr_valid_score.top());
                    curr_valid_score.push(stoi(curr_str));
                }
            } else {
                curr_valid_score.push(stoi(curr_str));
            }
        }
        while(!curr_valid_score.empty()) {
            sum += curr_valid_score.top();
            curr_valid_score.pop();
        } 
        return sum;
    }
};