class Solution {
public:
    int vis[100001];
    void dfs(int u , bool &ans,vector<int>adj[]){
        vis[u] = 1;
        for(auto i : adj[u]){
            if(vis[i] ==0){
                dfs(i,ans,adj);
            }
            else if(vis[i] == 1){
                ans = false;
            }
        }
        vis[u] =2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        memset(vis, 0 , sizeof vis);
        bool ans = true;
    
        for(int i = 0;i<numCourses;i++)
            if(!vis[i])
                    dfs(i ,ans , adj);
        return ans;
    }
};