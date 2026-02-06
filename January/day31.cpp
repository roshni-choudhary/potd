//744. Find Smallest Letter Greater Than Target
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        bool flag = false;

        for (int i = 0; i < letters.size(); i++) {
    char ch = letters[i];
    if (!flag && ch > target) {
        res = ch;
        flag = true;
    }
}
        return res;
    }
};