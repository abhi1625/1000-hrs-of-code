#include<iostream>
#include<string>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isPermutation(string str1, string str2) {
    //check if length of the two strings is same
    if (str1.size() != str2.size()) {
        return false;
    }

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    for (int i=0; i<str1.size(); i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string str1 = "test";
    string str2 = "estt";
    bool ans = isPermutation(str1, str2);

    if (ans == true) {
        cout << str1 << " is a permutation of " << str2 << endl;
    } else {
        cout << str1 << " is not a permutation of " << str2 << endl;
    }
    return 0;
}