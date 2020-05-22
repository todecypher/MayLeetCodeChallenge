class Solution {
public:
    int firstUniqChar(string s) {
        int h[26];
        memset(h, -1, sizeof h);
        for(int i= 0 ; i<s.length();i++){
            if(h[s[i]-'a'] ==-1)
                h[s[i]-'a'] = i;
            else
                h[s[i]-'a'] = -2;
        }
        
        int res = INT_MAX;
        
        for(int i=0;i<26;i++){
            if(h[i]!=-1 && h[i]!=-2 && h[i] <res)
                res = h[i];
        }
        return (res ==INT_MAX ? -1 : res);
    }

};