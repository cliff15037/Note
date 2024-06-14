/*
  This problem is DP, but there are different thought to finish it.
  The first is the traditional DP, use array to calculate.
  This is space(n), time(n), but space can be optimized to O(1)
*/
class Solution {
// prices:  1  2  3 0 2 
// cool  :  0  0  1 2 2
// buy   : -1 -1 -1 1 1 
// sell  :  0  1  2 2 3
// Each day can only do a thing
// cool[i] == s[i-1] || c[i-1] || b[i-1]
// buy[i]  == c[i-1]-p[i] || b[i-1]
// sell[i] == b[i-1]+p[i] || s[i-1]
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cool(n), buy(n), sell(n);
        buy[0] = -prices[0];
        for (int i=1 ; i<n ; i++) {
            cool[i] = max(sell[i-1], max( cool[i-1], buy[i-1]));
            buy[i] = max(cool[i-1]-prices[i], buy[i-1]);
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
        }

        return max(cool[n-1], sell[n-1]);
    }
};


/*
  The following solution is DFS/decision tree method with cache, also a kind of DP
*/
class Solution {
public:
/*
    There are three move: buy, sell, cooldown(do nothing)
    cooldown can happen in any position.
    buy and sell, are opposite, each position can only choose one.
*/  

    int dfs(int i, bool buying, vector<int>& prices, unordered_map<int, unordered_map<bool, int>> &dp) { //return maxProfit
        if (i>=prices.size()) return 0;
        if (dp[i][buying]) return dp[i][buying];
        //if (dp.count(i) && dp[i].count(buying)) return dp[i][buying];

        // Both buying state and selling state can choose to do cooling
        int cooldown = dfs(i+1, buying, prices, dp);//do nothing, keep the state of buying
        if(buying){
            //buying
            int buy = dfs(i+1, !buying, prices, dp) - prices[i];
            dp[i][buying] = max(cooldown, buy);
        } else {
            //selling
            int sell = dfs(i+2, !buying, prices, dp) + prices[i];
            dp[i][buying] = max(cooldown, sell);
        }
        return dp[i][buying];
    }

    int maxProfit(vector<int>& prices) {
        unordered_map<int, unordered_map<bool, int>> dp;// a position i corresponds to a bool, to a maxProfit value
        return dfs(0, true, prices, dp);
    }
};
