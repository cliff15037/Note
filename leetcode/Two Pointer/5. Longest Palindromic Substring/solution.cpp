// DP solution

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int n = s.size();
        
        if (n <= 1) return s;
        

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // start to break the question
        // there are 3 type of palindromic substring
        // 1. the char itself: 'c'
        // 2. the 2 identical char: "cc"
        // 3. a palindromic substring between 2 identical char: "a[palindromic]a" 

        // First, 1. and 2. can be done together, fill out some part of dp
        // The goal of dp is to get the best "left" and "len" to be used later
        // we'll use substr function in the end, need a start index (left) and a length (len)
        int left=0, len=1;
        for (int i=0 ; i<n ; i++) {
            dp[i][i] = true;

            if (i == n-1) break;
            
            dp[i][i+1] = s[i]==s[i+1];
            if ( dp[i][i+1] == true ) {
                left = i;
                len = 2;
            }
        }

        // Then, do the 3.
        // to correctly fill the dp, need to do it upside
        for (int i=n-2 ; i>=0 ; i--) {
            for ( int j=i+2 ; j<n ; j++) {
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);

                if (dp[i][j] && j-i+1>len) {
                    left = i;
                    len = j-i+1;
                }
            }
        }
        return s.substr(left, len);
    }
};


// two pointer solution

class Solution {
public:
    int checkPalin (string s, int left, int right) {
        int res;
        while (left>=0 && right<s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left -1;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        int start = 0, len = 0, maxLen = 0;;
        for (int i=0 ; i<n ; i++) {
            // palindromic substring can be even or odd: "abba" "aba"
            int lenEven = checkPalin(s, i, i+1);
            int lenOdd = checkPalin(s, i, i);

            int len = max(lenEven, lenOdd);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len-1)/2;
            }
        }

        return s.substr(start, maxLen);
    }
};
