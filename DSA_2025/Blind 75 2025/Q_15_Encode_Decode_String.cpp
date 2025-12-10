// c++ sol: https://youtu.be/-DtxbyTu5bU?si=nopbWy-cDkrYSx80

// Two solutions:- first to enter such a character that is outside of ASCII ranfe
// second one is to encode the length at atarting of words to act as a delimeter + tell about the length of the actual word, IT IS CALLED TRANSFER CHUNK DATA APPROCH AND IT IS USED IN HTTP PROTOCOL!

#include <bits/stdc++.h>
using namespace std;

class Solution_First_Version
{
public:
    string encode(vector<string> &strs)
    {
        string res = "";
        for (auto &str : strs)
        {
            for (auto &ch : str)
            {
                res.push_back(ch);
            }
            res.push_back((char)0xFFFFFF); // PUSH BACK A Special char(i.e outside ASCII RANGE bcz according to question ASCII can be included in words) after every word.
        }
        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        string cur = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == (char)0xFFFFFF) // when encounter this char save the word, empty the curr string and continue with rest of the string.
            {
                res.push_back(cur);
                cur = "";
            }
            else
            {
                cur.push_back(s[i]);
            }
        }
        return res;
    }
};

#define STRLEN 3
class Solution_SECOND_Version
{
public:
    string padding(string inp)
    {
        string outp = "",
               int n = inp.size();
        int zeroestopad = STRLEN - n;
        while (zeroestopad--)
        {
            outp.push_back('0');
        }
        for (auto &ch : inp)
        {
            outp.push_back(ch);
        }
        return outp;
    }

    string
    encode(vector<string> &strs)
    {
        string res = "";
        for (auto &str : strs)
        {
            string lenstr = padding(to_string(str.length()));
            for (auto &ch : lenstr)
            {
                res.push_back(ch);
            }
            for (auto &ch : str)
            {
                res.push_back(ch);
            }
        }
        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int i = 0;
        while (i < s.length())
        {
            int len = stoi(s.substr(i, STRLEN));
            i += STRLEN;
            string cur = "";
            while (len--)
            {
                cur.push_back(s[i]);
                i++;
            }
            res.push_back(cur);
        }

        return res;
    }
};
