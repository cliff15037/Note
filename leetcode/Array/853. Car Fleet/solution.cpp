/*
  Solution using stack
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> carsTime;

        for (int i = 0; i < position.size(); ++i) {
            carsTime.push_back({position[i], speed[i]});
        }
        
        sort(carsTime.begin(), carsTime.end()); // sorting according to the position

        stack<double> st;
        for (int i=n-1 ; i>=0 ; i--) {
            double time = (double)(target - carsTime[i].first) / carsTime[i].second;
            if ( !st.empty() && time <= st.top()) {
                continue;
            }
            st.push( time );
            
        }

        return st.size();
    }
};


/*
  Simplify the solution
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> needTime(n);

        for (int i=0 ; i<n ; i++) {
            double time = (double)(target - position[i]) / speed[i];
            needTime[i] = {position[i], time};
        }
        
        sort(needTime.begin(), needTime.end());

        double curTime = 0;
        int fleets = 0;
        for (int i=n-1 ; i>=0 ; i--) {
            if (needTime[i].second > curTime ) {
                fleets++;
                curTime = needTime[i].second;
            }
            
        }

        return fleets;
    }
};
