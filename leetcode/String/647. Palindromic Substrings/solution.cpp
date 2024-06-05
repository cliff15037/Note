/*
  Center Expansion Method, simple and better method, O(1) space and O(n^2) time.
*/
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for ( int i=0 ; i<n ; i++) {
            int left = i, right = i;
            while (left>=0 && right<n && s[left]==s[right]) {
                count++;
                left--;
                right++;
            }

            left = i;
            right = i+1;
            while (left>=0 && right<n && s[left]==s[right]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};


/*
  DP, O(n^2) space and O(n^2) time.
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        //回文有3種 1.字元本身 2.連續2個一樣: aa 
        //3.頭尾一樣，中間也是回文，eg: a[回文]a
        //先初始化1.和2.
        for(int i=0 ; i<n ; i++){
            dp[i][i]=true;
            count++;
            if(i<n-1){
                dp[i][i+1]= s[i]==s[i+1];
                if(dp[i][i+1]==true){
                    count++;
                }
            }
        }

        //3. 
        for(int i=n-3 ; i>=0 ; i--){
            for(int j=n-1 ; j>i+1 ; j--){
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
                if(dp[i][j]==true){
                    count++;
                }
            }
        }

        return count;
    }
};






