class Solution {
public:
/*
    This is a monotonic stack problem.
    Maintain a stack containing monotonic number.
*/
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<pair<int, int>> st;

        st.push({0, temperatures[0]});
        
        for (int i=1 ; i<n ; i++) {

            while ( !st.empty() && temperatures[i] > st.top().second ) {
                int index = st.top().first;
                answer[index] = i - index;
                st.pop();
            }

            st.push({i, temperatures[i]});
            
        }

        return answer;
    }
};
