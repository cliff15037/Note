/*
  Slow but intuitive decision tree method
*/
class Solution {
public:

    void decisionTree(vector<int>& nums, int target, int index, int &res, int temp) {
        if (index == nums.size()) {
            if (temp==target) {
                res++;
            }
            return;
        }

        // add it
        temp += nums[index];
        decisionTree(nums, target, index+1, res, temp);
        temp -= nums[index];

        // sub it
        temp -= nums[index];
        decisionTree(nums, target, index+1, res, temp);
        temp += nums[index];

        return;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int res=0;
        int temp=0;
        decisionTree(nums, target, 0, res, temp);

        return res;
    }
};

/*
  Decision tree with cache
*/
class Solution {
public:

    int decisionTree(vector<int>& nums, int target, int index, int temp, unordered_map<int, unordered_map<int, int>> &map) {
        if (index == nums.size()) {
            if (temp==target) {
                return 1;
            }
            return 0;
        }
        
        if (map.count(index) && map[index].count(temp)) {
            return map[index][temp];
        }

        // add it
        int add = decisionTree(nums, target, index+1, temp+nums[index], map);

        // sub it
        int sub = decisionTree(nums, target, index+1, temp-nums[index], map);

        map[index][temp] = add+sub;

        return map[index][temp];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int temp=0;
        unordered_map<int, unordered_map<int, int>> map;
        return decisionTree(nums, target, 0, temp, map);
    }
};



/*
  Fastest DP method
*/
class Solution {
    /*
        There must be a answer which can lead to target.
        Some element is positive and some is negative, combine to be target.
        The answer is the combine of P and Q subset: nums = {P, N}
        P is subset of positive, N is negative
        P + N = sum
        And P - N = target
        2P = sum + target
        P = (sum + target)/2
        So, the problem is : How many kind of subset P can we find, make the sum of P is (sum + target)/2
    */
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if ( (sum + target)%2 != 0 || sum < target ) return 0;

        int newTarget = (sum + target)/2;
        vector<int> dp(newTarget+1, 0); // index of dp is the target number, the element is the combination number
        dp[0] = 1; // There is 1 combination to sum up to be 0

        for (int num : nums) {
            for (int j=newTarget ; j-num>=0 ; j--) {
                // for a target j, we check if each num in nums can contribute to sum up to be j
                dp[j] = dp[j] + dp[j-num];
            }
        }

        return dp[newTarget];
    }
};
