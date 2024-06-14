
/*
  Decision tree method can solve, but slower than DP
*/
class Solution {
public:
    bool decisionTree(vector<int>& nums, int target, int index, int temp, unordered_map<int, unordered_map<int, bool>> &map) {
        if (index>=nums.size() || temp>target) return false;
        if (nums[index]==target || temp == target) return true;
        if (map.count(index) && map[index].count(temp)) return map[index][temp];
        // if (map[index][temp]) return map[index][temp]; this line is not a good style, extra construction

        bool result = false;
        // choose index
        if (temp + nums[index] <= target) {
            result = decisionTree(nums, target, index + 1, temp + nums[index], map);
        }

        // not choose index
        if (!result) {
            result = decisionTree(nums, target, index + 1, temp, map);
        }

        map[index][temp] = result;
        return result;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0, target=0;
        for (int i : nums) {
            sum += i;
        }
        if (sum%2 != 0) return false;

        target = sum/2;

        unordered_map<int, unordered_map<int, bool>> map;
        int temp=0;
        return decisionTree(nums, target, 0, temp, map); 
    }
};


/*
  We can use DP
*/
class Solution {
    /*
        DP solution:
            nums = [1,5,11,5]
            target = 11;
            dp index = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
                  dp = [t, f, f, f, f, f, f, f, f, f,  f,  f] initial state
                  for i : nums
                    we want to check if it can be used to achieve target 11 in dp
                    if it can contribute, then it could contribute from 10 to 11, from 9 to 10,......
                    Trace it down and we can know dp[1] is true, because it could contribute from 0 to 1
                    Then i=5,
                    Trace it down and we can know dp[6] is true
                    Then i=11,
                    so dp[11] is true
                    ......
    */
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i: nums) {
            sum += i;
        }
        if (sum%2 != 0) return false;

        int target = sum/2;

        vector<bool> dp(target+1, false);
        dp[0] = true;
        for (int x : nums) {
            for (int i=target ; i>0 ; i--) {
                if (i-x>=0 && dp[i-x]==true) {
                    dp[i] = dp[i-x];
                }
            }
        }

        return dp[target];
    }
};
