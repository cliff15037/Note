/*
    Quick Select algorithm
*/
class Solution {
public:
    int quickselective(int l, int r, int k, vector<int>& nums) {
        int pivot = nums[r];
        int p = l; // start from l, slowly move to right

        for (int i=l ; i<r ; i++) {
            if (nums[i]<pivot) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        // So now every element on the left side of p is less than pivot
        swap(nums[p], nums[r]); // swap nums[p] with pivot
        // So now every element on the right side of p is bigger than pivot

        if (p>k){
            return quickselective(l, p-1, k, nums);
        } else if (p<k) {
            return quickselective(p+1, r, k, nums);
        } else {
            return nums[k];
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n-k;// now, k is count from the right side, the Kth element

        return quickselective(0, n-1, k, nums);
    }
};



/*
  There is a DP method to solve
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;

        for(auto num : nums) {
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }

        vector<int> freq(maxValue - minValue + 1);

        for(auto num : nums) freq[num - minValue]++;

        for(int i = maxValue - minValue; i >= 0; i--) {
            k -= freq[i];
            if(k <= 0) return i + minValue;
        }

        return -1;
    }
};
