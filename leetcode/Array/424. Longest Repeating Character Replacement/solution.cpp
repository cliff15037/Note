/*
  Start from the first solution, which is not good enough, the time is O(26*n)
*/
class Solution {
public:
    int maxHelper(vector<int> &v) {
        int resMax = v[0];
        for(int i : v) {
            resMax = max(resMax, i);
        }
        return resMax;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int right=0, left=0;
        vector<int> count(26, 0);
        int result = 0;

        while ( right < n ) {
            count[s[right]-'A']++;

            while ( (right-left+1) - maxHelper(count) > k ) {
                count[s[left]-'A']--;
                left++;
            }

            result = max(result, right-left+1);
            right++;
        }

        return result;

    }
};



/*
  Slightly modify the solution, record maxFrequency each round.
*/
class Solution {
public:

    int characterReplacement(string s, int k) {
        int n = s.size();
        int right=0, left=0;
        int maxFrequency=0;
        vector<int> count(26, 0);
        int result = 0;

        while ( right < n ) {
            count[s[right]-'A']++;
            maxFrequency = max(maxFrequency, count[s[right]-'A']);
            while ( (right-left+1) - maxFrequency > k ) {
                count[s[left]-'A']--;
                left++;
            }

            result = max(result, right-left+1);
            right++;
        }

        return result;

    }
};
