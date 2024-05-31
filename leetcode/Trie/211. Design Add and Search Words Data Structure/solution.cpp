class TrieNode {
    public:
        unordered_map<char, TrieNode*> childrenMap;
        bool isWordEnd;
        TrieNode(){
            isWordEnd = false;
        }
};

class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node = root;
        for ( char c : word) {
            if ( !node->childrenMap.count(c) ) {
                node->childrenMap[c] = new TrieNode();
            }
            node = node->childrenMap[c];
        }
        node->isWordEnd = true;
    }
    
    bool searchDfsHelper(string word, int index, TrieNode *node ){
        int n = word.size();

        if (index == n && node->isWordEnd) {
            return true;
        }
        
        if ( !(word[index]=='.')){
            if ( !node->childrenMap.count(word[index]) ) {
                return false;
            }
            return searchDfsHelper(word, index+1, node->childrenMap[word[index]] );
        } else {
            // '.' can be any char, check all in childrenMap
            for(auto m : node->childrenMap) {
                if ( searchDfsHelper( word, index+1, m.second ) ){
                    return true;
                }
            }
            return false;
        }
    }

    bool search(string word) {
        return searchDfsHelper( word, 0, root );
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
