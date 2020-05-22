class Solution {
public:
    bool checkInclusion(string p, string s) {
        vector<int> res;
        int n = s.length();
        int k = p.length();
        int curr =0;
        
        if(s.length() < p.length())
            return false;
        
       vector<int>keep(26,0) , now(26,0);
        
        for(auto ch : p)
            keep[ch-'a']++;
        
        for(int i=0;i<k;i++){
            now[s[i]-'a']++;
        }
        
        for(int i=k;i<n;i++){
            if(now==keep)
                return true;
            now[s[i]-'a']++;
            now[s[i-k]-'a']--;   
        }
        if(now==keep)
            return true;
        return false;
    
    }
};