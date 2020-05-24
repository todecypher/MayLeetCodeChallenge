class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> h;
        for(auto i : s)h[i]++;
       
        priority_queue<pair<int ,char>>pq;
       
        for(auto i : h){
            pq.push({i.second , i.first});
        }
        
        string ans;
        while(!pq.empty()){
            char c =pq.top().second;
            int x = pq.top().first;
            pq.pop();
            
            while(x--) ans.push_back(c);
            
        }
        return ans;
    }
};