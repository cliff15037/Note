class TrieNode {
    public:
        unordered_map<char, TrieNode*> childrenMap;
        bool isEndOfWord;
        TrieNode() : isEndOfWord(false) {}     
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() {
       root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->childrenMap.count(c)) {
                node->childrenMap[c] = new TrieNode();
            }
            node = node->childrenMap[c];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for (char c : word) {
            if (!node->childrenMap.count(c)) {
                return false;
            }
            node = node->childrenMap[c];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char c : prefix) {
            if (!node->childrenMap.count(c)) {
                return false;
            }
            node = node->childrenMap[c];
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
