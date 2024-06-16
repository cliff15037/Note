class Solution {
public:
    // O(26*n)
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Map(26), s2Map(26);
        for(char c : s1) {
            s1Map[c - 'a']++;
        }
        
        for (int i = 0; i < s2.size(); i++) {
            s2Map[s2[i] - 'a']++;

            // when walking through s2, need to keep the sliding window length for s2Map
            // sliding window length is s1.size()
            if (i>=s1.size()) {
                s2Map[s2[i-s1.size()] - 'a']--;
            }

            if (s1Map == s2Map) { // This condition is O(26)
                return true;
            }
        }
        return false;
    }
};



class Solution {
public:
    // O(3n)
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Map(26, 0), s2Map(26, 0);

        for (char c : s1) {
            s1Map[c - 'a']++;
        }

        for (int i = 0; i < s1.size(); i++) {
            s2Map[s2[i] - 'a']++;
        }

        int match = 0;// mach only check a map element is true or false, not care about the difference
        for (int i = 0; i < 26; i++) {
            if (s1Map[i] == s2Map[i]) {
                match++;
            }
        }

        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++) {
            if (match == 26) {
                return true;
            }

            // Update the right side of the window
            s2Map[s2[r] - 'a']++;
            if (s2Map[s2[r] - 'a'] == s1Map[s2[r] - 'a']) {
                match++;
            } else if (s2Map[s2[r] - 'a'] == s1Map[s2[r] - 'a'] + 1) {
                //no matter s2Map larger than s1Map how much, the match is changed when diff == 1
                match--;
            }

            // Update the left side of the window
            s2Map[s2[l] - 'a']--;
            if (s2Map[s2[l] - 'a'] == s1Map[s2[l] - 'a']) {
                match++;
            } else if (s2Map[s2[l] - 'a'] == s1Map[s2[l] - 'a'] - 1) {
                match--;
            }
            l++;
        }

        return match == 26;
    }
};
