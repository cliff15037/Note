/*
  decisiontree method, time limit exceeded
*/
class Solution {
public:

    int decisionTree(int amount, vector<int>& coins, int index) {
        if (index==coins.size()) return 0;
        if (amount==0) return 1;
        if (amount<0) return 0;
        
        // choose it
        int choose = decisionTree(amount-coins[index], coins, index); // can choose it again

        // not choose it
        int notChoose = decisionTree(amount, coins, index+1);

        return choose + notChoose;
    }

    int change(int amount, vector<int>& coins) {
        int temp=0;
        return decisionTree(amount, coins, 0);
    }
};


/*
  decisiontree method with cache
*/
class Solution {
public:

    int decisionTree(int amount, vector<int>& coins, int index, unordered_map<int, unordered_map<int, int>> &map) {
        if (index==coins.size()) return 0;
        if (amount==0) return 1;
        if (amount<0) return 0;
        if (map.count(index) && map[index].count(amount)) return map[index][amount];

        // choose it
        int choose = decisionTree(amount-coins[index], coins, index, map); // can choose it again

        // not choose it
        int notChoose = decisionTree(amount, coins, index+1, map);

        map[index][amount] = choose + notChoose;
        return map[index][amount];
    }

    int change(int amount, vector<int>& coins) {
        int temp=0;
        unordered_map<int, unordered_map<int, int>> map;
        return decisionTree(amount, coins, 0, map);
    }
};


/*
  DP method
*/
class Solution {
public:
    /*
        eg. amount = 4, coins = [1,2]
        dp index = [0, 1, 2, 3, 4]
              dp = [1, 0, 0, 0, 0]
        check coin 1 :
              dp = [1, 1, 1, 1, 1] // all amount has only 1 combination, use coin 1, 
                                   // dp[3] now means there is 1 method to sum up to be 1 (only use coin 1)
        check coin 2:
              dp = [1, 1, 2, 2, 3] // only chack amount>=2, it is trivial amount 2 has 2 method.
                                   // dp[3] = "dp[3] from previous dp status" + "dp[1] which means methods using coin [1,2] to sum up to be 1"
                                   // Because we are considering using coin 2 in this round, 
                                   // so whatever dp[1] is now, it is the method number can directly contribute to dp[3], only need to use a coin 2
                                   // and so on...


    */
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);// each element is the combination number of the certain amount (index represent amount)
        dp[0] = 1; // there is only 1 combination method to sum up to be 0: choose no coin

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};





