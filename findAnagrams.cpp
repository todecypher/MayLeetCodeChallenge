class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.length();
        int k = p.length();
        int curr =0;
        
        if(s.length() < p.length())
            return res;
        
       vector<int>keep(26,0) , now(26,0);
        
        for(auto ch : p)
            keep[ch-'a']++;
        
        for(int i=0;i<k;i++){
            now[s[i]-'a']++;
        }
        
        for(int i=k;i<n;i++){
            if(now==keep)
                res.push_back(i-k);
            now[s[i]-'a']++;
            now[s[i-k]-'a']--;   
        }
        if(now==keep)
            res.push_back(s.length()-k);
        return res;
    }
};