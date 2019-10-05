#include<iostream>
#include<string>
#include<algorithm>

using std::string;
using std::cin;
using std::cout;
using std::endl;

bool isUnique(string& sentence) {
    // sort the string 
    std::sort(sentence.begin(), sentence.end());

    string::iterator it=sentence.begin();
    // char space = " ";
    for (it; it != sentence.end() -1; it++) {
        // cout << *it << " " << *(it+1) << endl;
        if (*it == *(it+1) && *it != ' ') {
            return false;
        }
    }
    return true;
}

int main() {
    string sentence = "  ";
    auto output = isUnique(sentence);
    if (output == true) {
        cout << "The sentence has all unique characters" << endl;
    } else {
        cout << "The sentence does not have all unique characters" << endl;
    }
    return 0;
}