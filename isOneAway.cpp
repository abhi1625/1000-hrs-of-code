#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


bool isOneAway(string &str1, string &str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    if (abs(len1 - len2) > 1) return false;

    string a, b;
    a = (len1 >=  len2) ? str1 : str2;
    b = (len1 <  len2) ? str1 : str2;

    bool oneEdit = false;
    string::iterator it1 = str1.begin();
    string::iterator it2 = str2.begin();
    for (it1, it2; it1 != str1.end() && it2 != str2.end();) {
        if(*it1 != *it2) {
            if (oneEdit) {
                return false;
            } 
            oneEdit = true;
            if (len1 == len2) {
                it1++;
                it2++;
            }
            else if (len1 > len2) {
                it1++;
            }
            else if (len1 < len2) {
                it2++;
            }
        }
        it1++;
        it2++;
    }
    return true;
}

int main() {
    string str1, str2;
    cout << "Enter first string" << endl;
    getline(cin, str1);
    cout << "Enter another string" << endl;
    getline(cin,str2);
    bool ans = isOneAway(str1, str2);
    if (ans) {
        cout << "String 1 and String 2 are one edit away" << endl;
    } else {
        cout << "String 1 and String 2 are not one edit away" << endl;
    }
    return 0;
}