class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
        }

        vector<vector<int>> resHelper(nums.size()+1);// index is the times, val is the corresponding number
        for(auto n : mp){
            resHelper[n.second].push_back(n.first);
        }
        
        vector<int> res;
        for(int i=nums.size() ; i>=0 ; i--){
            if(resHelper[i].size() != 0) {
                // resHelper[i] represent the num which has i times in nums
                for ( int j : resHelper[i]) {
                    res.push_back(j);
                    k--;
                }
            }
            if(k==0) break;
        }

        return res;
    }
};
