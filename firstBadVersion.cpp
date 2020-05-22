// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // [1.... b-1] [b ...n];
        int low = 1 , high = n;
        while(low <=high){
            int mid = low + (high-low)/2;
            if(isBadVersion(mid))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};