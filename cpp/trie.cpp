#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    vector<Trie *> children;
    bool isEnd;

public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false) {}
    ~Trie() {}
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (char& ch: word) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (char& ch: word) {
            if (node->children[ch - 'a'] == nullptr) {
                return false;
            }
            node = node->children[ch - 'a'];
        }
        return node->isEnd ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (char& ch: prefix) {
            if (node->children[ch - 'a'] == nullptr) {
                return false;
            }
            node = node->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */