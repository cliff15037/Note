/*
  I think this one and 69. Sqrt(x) are a pair
  I there are a string ooooooxxxxxxx
  278. is finding the first x, and 69. is finding the last o
  Can really memorize this question.
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int D(int n) {
        // [1, 2, ..., n]
        int l=1, r=n;
        while (l<r) {
            int m = l + (r-l)/2;

            if ( isBadVersion(m) ) {
                r = m-1;
            } else {
                l = m+1;
            }
        }

        if(isBadVersion(l)) {
            return l;
        } else{
            return l+1;
        }

    }
};
