class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l<=r) {// need to find a specific target, so need to check every element,
            //use l<=r rather l<r to do so
            int m = l + (r-l)/2;
            if (nums[m] == target) {
                return m;
            }

            if( nums[m] >= nums[l] ){ // m might equal to l
                //l~m is ascending
                if (nums[l]<=target && target<nums[m]){ // already check (nums[m] == target), but (nums[l]==target) is possible
                    // target in the left side of m
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else {
                // m ~ r is ascending
                if (target>nums[m] && target<=nums[r]) {
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
        }

        return -1;
    }
};
