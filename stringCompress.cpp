#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string stringCompress(string &str) {
    int count = 1;    
    string out{""};
    out += str[0];
    for (int i=1; i<str.length()+1; i++) {
        if (str[i-1] == str[i]) {
            count++;
        } else {
            out += std::to_string(count);
            out += str[i];
            count = 1;
            // check if the length of the output string is more than the input
            if (str.length() <= out.length()) {
                return str;
            }
        }
    }
    if (out.length() < str.length()) {
        return out;
    } else return str;
}

int main() {
    string str;
    cout << "Enter a string: " << endl;
    getline(cin, str);

    string output = stringCompress(str);
    cout << "Compressed string is: " << output << endl;

    return 0;
}