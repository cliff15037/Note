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









