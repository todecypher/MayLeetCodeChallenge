class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& A) {
        int local_max =0 , global_max =INT_MIN , local_min = 0, global_min = INT_MAX;  
        int total = 0 ;
        
        for(int i =0 ; i<A.size();i++){
            local_max = max(A[i] , local_max+A[i]);
            global_max = max(global_max , local_max);
            
            local_min = min(A[i] , local_min +A[i]);
            global_min = min(global_min , local_min);
            
            total +=A[i];
        }
        return (global_max >0 ? max(global_max , (total - global_min)) : global_max);
    }
};