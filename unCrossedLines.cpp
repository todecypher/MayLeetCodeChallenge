#define int long long
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        dp[0][0] = 0;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(A[i] == B[j])
                    dp[i+1][j+1] = 1+ dp[i][j];
                else
                    dp[i+1][j+1] = max(dp[i+1][j] , dp[i][j+1]);
            }
        }
       
        return dp[n][m];
    }
};
