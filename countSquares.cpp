class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        for(int i =1;i<matrix.size();i++){
            for(int j = 1;j<matrix[0].size();j++){
                if(matrix[i][j])
                    matrix[i][j] += min({matrix[i-1][j-1] , matrix[i-1][j] , matrix[i][j-1]}); 
            }
        }
        int n = matrix.size();
        int m =matrix[0].size();
        int res =0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                res+=matrix[i][j];
            }
        }
        return res;
    }
};