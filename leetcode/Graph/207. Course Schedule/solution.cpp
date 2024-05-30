class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visitSet;

    bool dfsHelper(int course) {
        if (visitSet.count(course)) return false;//there is a circle
        if (preMap[course].empty()) return true;  // there is no prerequisities, can complete

        visitSet.insert(course);// add into the visited path
        for (int i : preMap[course]) {
            if (!dfsHelper(i)) return false;
        }
        visitSet.erase(course);

        // a skill to enhance performance, the course already been checked, no need to check it next time
        preMap[course].clear();
        
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto p : prerequisites ) {
            preMap[p[0]].push_back(p[1]);
        }

        for ( int i=0 ; i<numCourses ; i++) {
            if ( !dfsHelper(i) ) {
                return false;
            }
        }
        return true;
    }
};
