#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int getCharNumber(const char& c) {
    int a = int{'a'};
    int z = int{'z'};
    int A = int{'A'};
    int Z = int{'Z'};
    int val = int{c};
    // cout << "val is " << val << endl;

    if (a <= val && val <= z) {
        return val - 'a';
    } else if (A <= val && val <= Z) {
        return val - 'A';
    }
    return -1;
}

bool checkMaxOneOdd(const vector<int> &table ) {
    bool foundOdd = false;
    for (int freq : table) {
        if (freq%2 == 1) {
            if (foundOdd == true) {
                return false;
            }
            foundOdd = true;
        }
    }
    return true;
}

bool isPermutationOfPalindrome(string str) {
    vector<int> table(getCharNumber('z') - getCharNumber('a') + 1, 0);
    // cout << "size of the array is : " << table.size() << endl;
    for (char &c : str) {
        int x = getCharNumber(c);
        if (x != -1) {
            table[x]++;
        }
    }
    return checkMaxOneOdd(table);
}

int main() {
    string str = "This is a th";
    string isPermutation = isPermutationOfPalindrome(str) ? "yes" : "no";
    cout <<str <<" is a permutation of a palindrome : " << isPermutation << endl;

    return 0;
}