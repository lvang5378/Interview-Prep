#include "include.h"

/********************************************************************
Building a Trie given a set of keys (strings) is as follow
1. get string s
2. set pointer p as the root
3. start with 1st char c in s
	3.1 if c not in p's child, add c to p
4. set p = p.c, go to step 3
5. set a value to the last char node (indicate it is a word, not a prefix)


Insertion


/********************************************************************/
class TrieNode
{
public:
    TrieNode *children[26];
    bool is_word;

    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(children, 0, sizeof(children));
        is_word = b;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)    {
		if (search(s)) return ;

        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> children[s[i] - 'a'] == NULL)
                p -> children[s[i] - 'a'] = new TrieNode();
            p = p -> children[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }

private:
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> children[key[i] - 'a'];
        return p;
    }
};
