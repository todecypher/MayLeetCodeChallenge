class Solution {
public:
    int color[2002];
    bool bfs(int u , vector<vector<int>>& graph ){
        queue<int> q; 
        color[u] =1;
        q.push(u);
        while(!q.empty()){
            int n=  q.size();
            while(n--){
                auto t=  q.front();
                q.pop();
                int c = color[t] ==1?2:1;
                for(auto i : graph[t]){
                    if(color[i]==-1){
                       color[i] = c;
                        q.push(i);
                    }
                    else{
                        if(color[t] == color[i])
                            return false;
                    }
                }
            }
        }
        return true;
    }
     void dfs(int u , int p ,vector<vector<int>>& graph ,bool &ans){
        if(p==-1){
            color[u] =1;
        }
        else{
            color[u] = color[p] ==1? 2:1;
        }
        for(auto to : graph[u]){
            if(color[to] == -1){
                dfs(to , u,graph,ans);
                ans &= (color[to]!=color[u]);
            }
            else{
                ans &=((color[to]!=color[u]));
            }
           
        }
        
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1);
        
        for(auto l : dislikes){
            graph[l[0]].push_back(l[1]);
            graph[l[1]].push_back(l[0]);
           
        }
        memset(color, -1, sizeof color);

        bool ok = true;
        
        for(int i =1 ;i<=N;i++){
            if(color[i]==-1 and !graph[i].empty()){
               dfs(i,-1,graph,ok);
                // bool tok =bfs(i,graph); 
                // ok &=tok;
            }
        }
        return ok;
    }
};