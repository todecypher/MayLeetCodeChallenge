class Solution {
public:
    int dist(int X , int Y){   
        return (X*X)+ (Y*Y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int> distance;
        
        for(auto i : points){
            distance.push_back(dist(i[0],i[1]));
        }
        
        priority_queue<pair<int,int>> pq;
        
        for(int i =0;i<K;i++){
            pq.push({distance[i], i});
        }
        
        for(int i = K;i<points.size();i++){
            if(pq.top().first > distance[i]){
                pq.pop();
                pq.push({distance[i],i});
            }
        }
        
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
        
    }
};