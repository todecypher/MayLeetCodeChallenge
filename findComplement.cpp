class Solution {
public:
    int findComplement(int num) {
        int ans = 0 ,ct =0 ;
        while(num){
            if(!(num&1))
                ans = ans | (1<<ct);
            ct++;
            num>>=1;
        }
        return (ans);
    }
};
