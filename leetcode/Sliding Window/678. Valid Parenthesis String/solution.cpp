class Solution {
public:
/*
    Greedy algo, try to find the max and min possible number of '('
    If it is a legal string, number of '(' should be 0 in the end
*/
    bool checkValidString(string s) {
        int max=0, min=0; // recorder the number of '('
        for ( int i=0 ; i<s.size() ; i++) {
            if ( s[i]=='(' ) {
                max++;
                min++;
            }
            else if ( s[i]==')') {
                max--;
                min--;
            }
            else if ( s[i]=='*' ) {
                max++;// consider * as '('
                min--;// consider * as ')'
            }

            if (max<0) return false;
            if (min<0) min = 0;
            
        }

        return min==0;
    }
};
