/*
  This is the solution follows the ordinary binary search method.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) { // use "<=" because we want to check each element 
            if (nums[l] <= nums[r]) {  // if the all left to right is ascending
                return nums[l];
            }

            int m = l + (r - l) / 2;

            // check if the middle is the smallest
            if (
                (m == 0 || nums[m - 1] > nums[m]) && 
                (m == nums.size() - 1 || nums[m + 1] > nums[m])
                ) {
                return nums[m];
            }


            if (nums[m] >= nums[l]) {
                l = m + 1;  // min in the right
            } else {
                r = m - 1;  // min in the left
            }
        }

        return -1;  
    }
};


/*
  This solution is for this question.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while (l < r) { // use "<" because we can stop when l is neighbor of r, don't need to check l==r
            int mid = l + (r - l) / 2;  // prevent overflowing
            if (nums[mid] < nums[r]) {
              // mid to r is ascending
                r = mid;  // min on the mid or in mid's left
            } else {
                l = mid + 1;  // min in the mid's right
            }
        }
        
        return nums[l];  // Or nums[r], cause now l == r
    }
};


