
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
public:
    TrieNode *root;
    char endSymbol;
    const endChar = '*';
    
    SuffixTrie(string my_str) {
        root = new TrieNode();
        fillTree(my_str);
    }
    
    void fillTree(string str) {
        for (int i = 0; i < str.length(); ++i) {
            insertHelper(i, str);
        }
    }
    
    void insertHelper(int i, string str) {
        TrieNode *node = root;
        for (int j = i; j < str.length(); j++) {
            char letter = str[j];
            if (node->children.find(letter) == node->children.end()) {
                TrieNode *newNode = new TrieNode();
                node->children.insert({letter, newNode}); 
            }
            node = node->children[letter];
        }
        node->children.insert({this->endSymbol, NULL});
    }
    
    bool contains(string str) {
        TrieNode *node = root;
        for (char letter : str) {
            if (node->children.find(letter) == node->children.end()) {
                return false;
            }
            node = node->children[letter];
        }
        return node->children.find(this->endSymbol) != node->children.end();
    }
}

int main () {
    return 0;
}
