#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.length()!=0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

class Solution {
    private:
    bool checkequal(int a[26], int b[26]){
        for (int i = 0; i < 26; i++)
        {
            if (a[i]!=b[i])
            {
                return 0;
            }
            return 1;
        }
        
    }
public:
    string findpermutation(string s1, string s2) {
        //char count array
        int count1[26] = {0};


    
    for(int i=0; i<s1.length(); i++) {
       int index = s1[i]-'a';
       count1[index]++;
    }
    // traverse s2 string in window of size s2 length and compare

    int i=0;
    int windowsize=s1.length();
    int count2[26] = {0};
    while (i<windowsize)
    {
        int index = s2[i]-'a';
        count2[index]++;
        i++;
    }
    if(checkequal(count1,count2)){
        return 1;
    }
    while (i<s2.length())
    {
        char newchar = s2[i];
        int index = newchar - 'a';
        count2[index]++;

        char oldchar = s2[i-windowsize];
        int index = oldchar - 'a';
        count2[index]--;

        i++;

        if(checkequal(count1,count2)){
        return 1;
        }
    }
    return 0;
    

};