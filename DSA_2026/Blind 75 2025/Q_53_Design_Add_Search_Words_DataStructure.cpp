/*
211. Design Add and Search Words Data Structure
Medium
Topics
premium lock icon
Companies
Hint
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.


Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True


Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.
*/

#include <bits/stdc++.h>
using namespace std;
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wyUO7Oq9uS4
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/

class WordDictionary
{
public:
    struct trieNode
    {
        trieNode *children[26];
        bool isEndOfWord;
    };

    trieNode *getNode()
    {
        trieNode *newNode = new trieNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    /** Initialize your data structure here. */
    trieNode *root;

    WordDictionary()
    {
        root = getNode();
    }

    void addWord(string word)
    {
        trieNode *crawler = root;

        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (!crawler->children[index])
                crawler->children[index] = getNode();

            crawler = crawler->children[index];
        }

        crawler->isEndOfWord = true;
    }

    bool searchUtil(trieNode *root, string word)
    {
        trieNode *crawler = root;

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (ch == '.')
            {

                for (int j = 0; j < 26; j++)
                {
                    if (crawler->children[j] != NULL)
                        if (searchUtil(crawler->children[j], word.substr(i + 1)))
                            return true;
                }

                return false;
            }
            else if (crawler->children[ch - 'a'] == NULL)
            {
                return false;
            }

            crawler = crawler->children[ch - 'a'];
        }
        return (crawler != NULL && crawler->isEndOfWord);
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }
};