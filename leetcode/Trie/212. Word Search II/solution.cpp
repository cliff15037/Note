class TrieNode {
    public:
        unordered_map<char, TrieNode*> childrenMap;
        bool isWordEnd;
        TrieNode(): isWordEnd(false){}
};

class Trie {
public:
    TrieNode* root = new TrieNode();

    void addWord(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->childrenMap.count(c)) {
                node->childrenMap[c] = new TrieNode();
            }
            node = node->childrenMap[c];
        }
        node->isWordEnd = true;
    }
};


class Solution {
public:
    void dfsHelper(vector<vector<char>>& board, int i, int j, string foundWord, 
                    TrieNode *node, vector<vector<bool>> &visited, unordered_set<string> &resCollect) {
        if (i < 0 || 
            i >= board.size() || 
            j < 0 || 
            j >= board[0].size() || 
            visited[i][j] || 
            !node->childrenMap.count(board[i][j])
            ) {
            return;
        }

        visited[i][j] = true;
        node = node->childrenMap[board[i][j]];
        foundWord += board[i][j];
        if (node->isWordEnd) {
            resCollect.insert(foundWord);
        }

        dfsHelper(board, i+1, j, foundWord, node, visited, resCollect);
        dfsHelper(board, i-1, j, foundWord, node, visited, resCollect);
        dfsHelper(board, i, j+1, foundWord, node, visited, resCollect);
        dfsHelper(board, i, j-1, foundWord, node, visited, resCollect);

        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string s : words) {
            trie.addWord(s);
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        unordered_set<string> resCollect;// This is to collect result words, avoiding multiple same words in result
        vector<string> resWords;// this is only used to transfer "resCollect" to the return type 

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfsHelper(board, i, j, "", trie.root, visited, resCollect);
            }
        }


        for (const string& word : resCollect) {
            resWords.push_back(word);
        }

        return resWords;
    }
};
