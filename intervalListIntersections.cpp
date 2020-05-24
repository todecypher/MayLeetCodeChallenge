class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>merge;
        int i= 0, j=0,n=A.size(),m=B.size();
        
        while(i<n and j < m){
            int max_start = max(A[i][0] , B[j][0]);
            int min_end = min(A[i][1] , B[j][1]);
            if(max_start <= min_end){
                merge.push_back({max_start , min_end});
            }
            
            if(A[i][1] < B[j][1])
                i++;
            else
                j++;
        }
        return merge;
    }
};