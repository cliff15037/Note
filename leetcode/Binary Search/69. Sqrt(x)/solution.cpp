/*
  solution of l<r
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return x;
        int l = 1, r = x;

        while (l<r) {
            int m = l + (r-l)/2;
            if (m == (x / m)) {
                return m;
            }
                
            if ( m > x/m) {
                r = m-1;// m is out of range
            } else {
                l = m+1;
            }
        }

        //In final round: l, r is the 2 element that have not been checked, either l = m+1; or r = m-1;
        //l = m+1 => l==r, use if condition below to check.
        //r = m-1 =>r,l and the position r eas checked, m is too big, so answer is l-1
        if (l > x / l) {
            return l - 1;
        }
        return l;
    }
};



/*
  solution of l<=r
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return x;
        int l = 1, r = x;

        while (l<=r) {
            int m = l + (r-l)/2;
            if (m == (x / m)) {
                return m;
            }
                
            if ( m > x/m) {
                r = m-1;// m is out of range
            } else {
                // Before final round, when l and r are neighbor: l, r
                // m is on the l
                // This 2 elements are last 2 we need to check
                // because we want to find lower bound, m now might be the answer
                // but, we still need to check r, maybe r could directly be the answer?
                // so l = m+1 = r
                // Thus, l==r==m, go to next while loop
                l = m+1;
            }
        }

        // In final round l==r==m


        // finally, l>r
        // and we still not get the answer from m, it means 
        return l-1;
    }
};
