/*
  Bellman-Ford, DP method
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // define a dp, dp[i][j] means can go to j in i steps
        vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX));
        dp[0][src] = 0;

        for ( int i=1 ; i<k+2 ; i++) {
           
            dp[i][src] = 0;// src always be zero

            for (auto flight : flights) {
                int s=flight[0], d=flight[1], p=flight[2] ;
                if (dp[i-1][s] != INT_MAX) {
                    dp[i][d] = min(dp[i][d], dp[i-1][s] + p);
                }
            }
                
        }

        // result, check k + 1
        int result = INT_MAX;
        for (int i = 1; i <= k + 1; i++) {
            result = min(result, dp[i][dst]);
        }

        return result == INT_MAX ? -1 : result;
    }
};


/*
  We can optimize the space complexity
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // define a dp, dp[i][j] means can go to j in i steps
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for ( int i=0 ; i<k+1 ; i++) {
            vector<int> tempPrices = prices;
            for ( auto flight : flights) {
                int s = flight[0], d = flight[1], p = flight[2];
                if (prices[s] != INT_MAX) {
                    if (prices[s] + p < tempPrices[d]) {
                        tempPrices[d] = prices[s] + p;
                    }
                }
            }
            
            prices = tempPrices;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

