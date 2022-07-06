#include <bits/stdc++.h>
#include<iostream>
using namespace std;


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;


    TrieNode(char ch){
        data = ch;
        for (int i = 0; i <26; i++)
        {
            children[i] = NULL;
        }       
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch){
        root = new TrieNode(ch);
    }
    void insertUtil(TrieNode* root, string word){ //tc=0(length of word)
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        
        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root-> children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root, word);
    }

    void lcp(string str, string &ans){ //tc=0(m*n), sc=0(m*n)

        for(int i=0; i<str.length(); i++){
            char ch = str[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                //age bdh jao
                int index = ch -'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root ->isTerminal){
                //terminal m bhi bhag jao no need to do anything
                break;
            }
        }
    }

};

string longestCommonPrefix(vector<string> &arr, int n){ //ek child jb tk tb tk sahi h
    Trie *t = new Trie('\0');
    //insert  all strings into trie 
    for(int i=0; i<n; i++){
        t->insertWord(arr[i]);
    }

    string first =  arr[0];
    string ans="";

    t->lcp(first, ans);
    return ans;
}












string longCommPre(vector<string> &arr, int n){ //tc=(m*n) sc=0(1)
   
   string ans = "";
   
    //for traversing all characters of first string
    for(int i=0; i<arr[0].length(); i++){
        char ch = arr[0][i];
    

        bool match = true;
        //for comparing characters with rest of the string
        for (int j = 1; j < n; j++)
        {
        //not match
        if(arr[j].size() < i || ch != arr[j][i]){
            match = false;
            break;
        }

        if(match == false){
            break;
        }
        else{
            ans.push_back(ch);
        }
        }
    }
    return ans;
}