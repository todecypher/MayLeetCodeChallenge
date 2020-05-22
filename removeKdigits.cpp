class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string s;
        int total = num.length() - k;
        
        for(int i =0 ; i<num.size() ;i++){
            while(!s.empty() and s.back() > num[i] and k>0){
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        
       s.erase(total , string::npos);
        
        //zero leading
        int i=0;
        for(; s[i]=='0' ;i++);
        s.erase(0, i);
        
        return (s.empty() ? "0" : s);
    }
};