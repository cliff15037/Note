/*
  This is a DP solution, try to think where we come to DP. It is decision tree.
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        dp[n-1] = 1;
        int resMax = 1;


        for ( int i=n-2 ; i>=0 ; i--) {
            for ( int j=i+1 ; j<n ; j++) {
                if (nums[i]<nums[j]) {
                    dp[i] = max(1 + dp[j], dp[i]);
                    resMax = std::max(resMax, dp[i]);
                } 
            }
        }

        return resMax;
    }
};
