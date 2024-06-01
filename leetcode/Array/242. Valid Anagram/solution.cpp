class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        if (sLen != tLen) return false;

        unordered_map<char, int> mapS, mapT;

        for (int i=0 ; i<sLen ; i++) {
            mapS[s[i]]++;
            mapT[t[i]]++;
        }

        for (auto m : mapS) {
            if (mapT[m.first] != m.second) {
                return false;
            }
        }

        return true;
    }
};



/*
  This is a better method with O(1) space
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        if (sLen != tLen) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for( int i=0 ; i< sLen ; i++) {
            if (s[i]!=t[i]) return false;
        }

        return true;
    }
};
