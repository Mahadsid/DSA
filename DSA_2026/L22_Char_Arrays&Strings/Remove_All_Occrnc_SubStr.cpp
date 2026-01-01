// LeetCode 1910
// Remove all occurence of a substring from a string example i/p= 'd a a b c b a a b c b c' o/p = 'd a b',
// explanation in
// step 1 after reemoving first abc we get:   'd a b a a b c b c'
// step2: 'd a b a b c'
// step3 : 'd a b'

#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {

        while (s.length() != 0 && s.find(part) < s.length())
        {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};
