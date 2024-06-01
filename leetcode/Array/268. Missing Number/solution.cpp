/*
    This problem has at least 3 solutions
    1. straightforward mapping solution, take O(n) time and spaze(n)
    2. XOR solution, O(n) time and O(1)space
    3. easy solution simplily sum up, O(n) time and O(1)space
*/

// This is XOR solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i=0 ; i<=nums.size() ; i++) {
            res ^= i;
        }

        for (int i=0 ; i<nums.size() ; i++) {
            res ^= nums[i];
        }

        return res;
    }
};




// This is easy solution using summing up
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int lackSum = 0;

        for (int i=0 ; i<=nums.size() ; i++) {
            sum += i;
        }

        for (int i : nums) {
            lackSum += i;
        }

        return sum - lackSum;
    }
};
