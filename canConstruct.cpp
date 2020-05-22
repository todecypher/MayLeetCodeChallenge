class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int h[26];
        memset(h , 0 , sizeof h);
        
        for(auto i : ransomNote)
            h[i-'a']++;
        for(auto i : magazine)
            if(h[i-'a']>0)
                h[i-'a']--;
    
        for(int i =0 ;i<26;i++)
            if(h[i] !=0)  
                return false;
        return true;
    
    }
};