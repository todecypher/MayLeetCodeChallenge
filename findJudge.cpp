class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int>out_edge,in_edge;
        int ans =-1;
        
        for(auto i : trust){
            out_edge[i[0]] = 1;
            in_edge[i[1]]++;
        }
        
        for(int i =1; i<=N;i++)
            if(out_edge[i] ==0){
                if(in_edge[i] == N-1){
                    return i;
                }
            }
        
        return ans;
    }
};