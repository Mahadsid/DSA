#include <bits/stdc++.h>
#include<iostream>
using namespace std;


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for (int i = 0; i <26; i++)
        {
            children[i] = NULL;
        }       
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
        int index = word[0] - 'A';
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


    bool searchUtil(TrieNode* root, string word){//0(l)
        //base case
        if(word.length() == 0){
            return root->isTerminal;  
        }

        //aasumption all words are in caps
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root-> children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        //recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }


    bool prefixUtil(TrieNode* root, string prefix){
        //base case
        if(prefix.length() == 0){
            return true;  
        }

        //aasumption all words are in caps
        int index = prefix[0] - 'A';
        TrieNode* child;

        //present
        if(root-> children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        //recursion
        return prefixUtil(child, prefix.substr(1)); 
    }
    bool startsWith(string prefix){
        return prefixUtil(root, prefix);
    }


    void removeUtil(TrieNode* root, string word){
       //base case
       if(word.length() == 0){
           root->isTerminal = false;
       }

       //aasumption all words are in caps
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root-> children[index] != NULL){
            child = root->children[index];
        }
        else{
            return;
        }

        //recursion
        return removeUtil(child, word.substr(1));
    }
    void removeWord(string word){
        removeUtil(root, word);
    }

};

int main(){

    Trie *t =  new Trie();
    
    t->insertWord("ARM");
    t->insertWord("ART");
    cout << "present or not " << t->searchWord("ARM") << endl;
    t->removeWord("ARM");
    cout << "present or not " << t->searchWord("ARM") << endl;
    

    return 0;
}
