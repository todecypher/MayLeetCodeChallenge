class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char , int > mp;
        for(auto i : J) mp[i] =1;
        int ans = 0 ;
        for(auto i : S) {
            if(mp[i]) ans+=1;
        }
        return ans;
    }
};