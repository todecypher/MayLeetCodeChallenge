class Solution {
public:
    
    int solve(int i , int j  ,string s, string t,vector<vector<int>> &dp){
        
        if(j==t.length()){
            return s.length()-i;
        }
        if(i == s.length()){
            return t.length()-j;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i] == t[j]){
            return solve(i+1 , j+1 ,s,t,dp);
        }
        int x = solve(i, j+1,s,t,dp); //Insert 
        int y = solve(i+1,j ,s,t,dp);   //Delete
        int z = solve(i+1,j+1,s,t,dp); //Replace
        
        return dp[i][j] = 1+min({x,y,z});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1 ,vector<int>(word2.length()+1 , -1));
        
        return solve(0,0,word1,word2 ,dp);
    }
};