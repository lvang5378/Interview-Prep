##Trie

###Most important component in Trie class:
#### ----TrieNode * children[26]；  
#### ----bool is_word;

    class TrieNode{
    public:
       TrieNode *children[26];
        bool is_word;

       // Initialize your data structure here.
       TrieNode(bool b = false){
           memset(children, 0, sizeof(children));
            is_word = b;
       }
    };

    class Trie{
       TrieNode *root;
    public:
       Trie(){
           root = new TrieNode();
       }
       void insert(string word){}
       void search (string word){}
       void startWith(string prefix){}
    private:
        TrieNode* find(string key){}
    }
