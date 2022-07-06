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

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){ //tc=0(length of word)
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //aasumption all words are in caps
        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root-> children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursion

        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word){
        insertUtil(root, word);
    }


    vector<vector<string>> getSuggestions(string &queryStr){
    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for(int i=0; i < queryStr.length(); i++){
        char lastch = queryStr[i];

        prefix.push_back(lastch);

        //check for lastch
        TrieNode* curr = prev->children[lastch - 'a'];

        //if not found
        if(curr == NULL){
            break;
        }

        //if found
        vector<string> temp;
        printSuggestion(curr, temp, prefix);

        output.push_back(temp);
        temp.clear();
        prev = curr;
        
    }
    return output;
    }

    void printSuggestion(TrieNode* curr, vector<string> &temp, string prefix){
    if(curr->isTerminal){
        temp.push_back(prefix);
    }

    for(char ch = 'a'; ch <= 'z'; ch++){
        TrieNode* next = curr->children[ch-'a'];
        if(next != NULL){
            prefix.push_back(ch);
            printSuggestion(next, temp, prefix);
            prefix.pop_back();
        }
    }
    }
    
};

//sc=0(m*n), sc=0(n*m2) worst case

vector<vector<string>> phoneDictionary(vector<string> &contactList, string &queryStr){

    //creation of trie
    Trie *t = new Trie();

    //insert all contacts in trie
    for(int i=0; i < contactList.size(); i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    //return ans
    return t->getSuggestions(queryStr);

}