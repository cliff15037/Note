/*
  This is a better solution use DP
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int resMax = nums[0];

        for ( int i=1 ; i<nums.size() ; i++) {
            int temp = curMax;
            curMax = max( max(nums[i]*curMax, nums[i]*curMin), nums[i]);
            curMin = min( min(nums[i]*temp, nums[i]*curMin), nums[i]);
            resMax = max(curMax, resMax);
        }

        return resMax;

    }
};


/*
  This is a solution use DP, but space complexity is not optimized
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        int dpMax[nums.size()];
        int dpMin[nums.size()];
        dpMax[0] = max(maxNum, nums[0]);
        dpMin[0] = min(minNum, nums[0]);
        int maxResult = nums[0];

        for(int i=1 ; i<nums.size() ; i++){
            dpMax[i] = max(max(nums[i]*dpMax[i-1], nums[i]*dpMin[i-1]), nums[i]);
            dpMin[i] = min(min(nums[i]*dpMax[i-1], nums[i]*dpMin[i-1]), nums[i]);
            maxResult = max( max(dpMax[i], dpMin[i]), maxResult);
            
        }

        return maxResult;
    }
};
