/*
  I think this problem is too difficult to solve.
  But it does make me feel interested.
  We can start from thinking a dfs solution, which can cost lots of time.
  Then use cache to enhance it.
*/

class Solution {
public:
    
    bool dfsHelper(int i, int j, string s, string p) {
        // i is pointer for s, j is for p
        // p and s end at the same time
        if (i>=s.size() && j>=p.size()) {
            return true;
        }

        if (j>=p.size()) {
            return false;
        }

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // This is a special match with * following
        if (j+1<p.size() && p[j+1]=='*') {
            // have 2 method, don't use * so j+2, or use *
            return dfsHelper(i, j+2, s, p) ||
                    (match && dfsHelper(i+1, j, s, p));
        }
        
        // This is a normal match of a char
        if (match) {
            return dfsHelper(i+1, j+1, s, p);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return dfsHelper(0, 0, s, p);
    }
};


class Solution {
public:
    
    bool dfsHelper(int i, int j, string &s, string &p, unordered_map<int, unordered_map<int, bool>> &cache) {
        
        if (cache.count(i) && cache[i].count(j)) {
            return cache[i][j];
        }

        // i is pointer for s, j is for p
        // p and s end at the same time
        if (i>=s.size() && j>=p.size()) {
            return true;
        }

        if (j>=p.size()) {
            return false;
        }

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // This is a special match with * following
        if (j+1<p.size() && p[j+1]=='*') {
            // have 2 method, don't use * so j+2, or use *
            cache[i][j] = dfsHelper(i, j+2, s, p, cache) ||
                    (match && dfsHelper(i+1, j, s, p, cache));
            return cache[i][j];
        }
        
        // This is a normal match of a char
        if (match) {
            cache[i][j] = dfsHelper(i+1, j+1, s, p, cache);
            return cache[i][j];
        }

        return false;
    }

    bool isMatch(string s, string p) {
        unordered_map<int, unordered_map<int, bool>> cache;
        return dfsHelper(0, 0, s, p, cache);
    }
};
