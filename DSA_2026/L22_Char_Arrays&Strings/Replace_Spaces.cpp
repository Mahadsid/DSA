// Replace Spaces with @40 anywhere a space is encontered in a string.
#include <string>
#include <iostream>
using namespace std;
string replaceSpaces(string &str)
{
    string temp = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp;
}

//+++++++++++++++++++++++++++++++++++++++++++ IN-PLACE SOL +++++++++++++++++++++++++++++++++++++++++++++
#include <bits/stdc++.h>
using namespace std;

string replaceSpacesInPlace(string &str)
{

    int spaces = 0;
    int n = str.length();

    // Step 1: count number of spaces
    for (char c : str)
    {
        if (c == ' ')
            spaces++; // count spaces
    }

    // Each space adds 2 extra chars (@40 -> 3 chars, space is 1)
    int newLength = n + spaces * 2;

    str.resize(newLength); // expand string to required size

    int i = n - 1;         // pointer at original end
    int j = newLength - 1; // pointer at new end

    // Step 2: move characters from back to front
    while (i >= 0)
    {

        if (str[i] == ' ')
        {                   // when space is found
            str[j--] = '0'; // place '0'
            str[j--] = '4'; // place '4'
            str[j--] = '@'; // place '@'
            i--;            // move left in original part
        }
        else
        {
            str[j--] = str[i--]; // copy original char backwards
        }
    }

    return str; // modified in place
}

int main()
{
    string s = "I love coding";
    replaceSpacesInPlace(s);
    cout << s; // Output: I@40love@40coding
}

/*
| Operation             | Complexity                                                  |
| --------------------- | ----------------------------------------------------------- |
| Counting spaces       | O(n)                                                        |
| Back-to-front filling | O(n)                                                        |
| **Total Time**        | **O(n)**                                                    |
| **Space**             | **O(1)** in-place (resize allowed but no extra temp string) |


*/