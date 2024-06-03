class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for ( int i=0 ; i<amount+1 ; i++) {
            for (int c : coins) {
                if (i-c >= 0) {
                    dp[i] = min(dp[i-c]+1, dp[i]);
                }
            }
        }

        if (dp[amount] != amount+1) {
            return dp[amount];
        } else {
            return -1;
        }
    }
};
