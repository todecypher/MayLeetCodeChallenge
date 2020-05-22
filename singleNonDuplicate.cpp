class Solution {
public:
    int single(vector<int>& nums , int low , int high){
        if(low >= high) return nums[low];
        int mid = low + (high - low)/2;
        
        int on_right = (high - mid +1) ;
        int on_left = mid-low+1;
        
        if(nums[mid+1] == nums[mid]){
            if(on_right % 2 ==0)
                return single(nums , low , mid-1);
            else
                return single(nums , mid+2 , high);
        }
        else if(nums[mid-1] == nums[mid]){
            if(on_left % 2==0)
                return single(nums , mid+1 ,high);
            else
                return single(nums , low , mid-2);
        }
        else
            return nums[mid];
        
    }
    
    int singleNonDuplicate(vector<int>& nums) {
       
        if(nums.empty()) return -1;
        if(nums.size() == 1) return nums[0];
        return single(nums , 0 , nums.size()-1);
        
    }
};