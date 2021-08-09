#include <bits/stdc++.h>
using namespace std;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        string tmp = "";
        dfs(characters, combinationLength, tmp);
    }

    void dfs(string& chas, int length, string& str) {
        if (length == 0) {
            combs.push_back(str);
            return;
        }
        for (int i = 0; i < chas.size() - 1; i++) {
            str += chas[i];
            dfs(chas, --length, str);
        }
    }

    string next() {

    }
    
    bool hasNext() {

    }
private:
    vector<string> combs;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */